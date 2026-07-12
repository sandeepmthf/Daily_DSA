class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        
     
        set<int> uniqueElements(arr.begin(), arr.end());
        

        unordered_map<int, int> rank;
        int r = 1;
        for (int val : uniqueElements) {
            rank[val] = r++;
        }
        

        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(rank[arr[i]]);
        }
        
        return result;
    }
};