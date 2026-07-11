class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> v;
        stack<int> s;
        int n = nums.size();

        // Push all elements once
        for (int i = n - 1; i >= 0; i--) {
            s.push(nums[i]);
        }

        // Your original logic
        for (int i = n - 1; i >= 0; i--) {

            if (s.empty()) {
                v.push_back(-1);
            }
            else if (s.top() > nums[i]) {
                v.push_back(s.top());
            }
            else {
                while (!s.empty() && s.top() <= nums[i]) {
                    s.pop();
                }

                if (s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top());
            }

            s.push(nums[i]);
        }

        reverse(v.begin(), v.end());
        return v;
    }
};