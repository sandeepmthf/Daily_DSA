class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> ord;
        ord.reserve(n);

        for (int i = 0; i < n; i++)
            ord.push_back({nums[i], i});

        sort(ord.begin(), ord.end());

        // position of original node in sorted order
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[ord[i].second] = i;

        // connected components in sorted order
        vector<int> comp(n);
        int cid = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (ord[i].first - ord[i - 1].first > maxDiff)
                cid++;
            comp[i] = cid;
        }

        // nxt[i] = farthest index reachable in one edge
        vector<int> nxt(n);
        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r + 1 < n &&
                   ord[r + 1].first - ord[l].first <= maxDiff)
                r++;
            nxt[l] = r;
            if (r == l) r++;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = nxt;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int a = pos[q[0]];
            int b = pos[q[1]];

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            if (comp[a] != comp[b]) {
                ans.push_back(-1);
                continue;
            }

            if (a > b) swap(a, b);

            int cur = a;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};