class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();

   
        vector<int> power3(numSlots + 1, 1);

        for (int i = 1; i <= numSlots; i++) {
            power3[i] = power3[i - 1] * 3;
        }

        int totalStates = power3[numSlots];

       
        vector<int> dp(totalStates, -1);

        dp[0] = 0;

        for (int mask = 0; mask < totalStates; mask++) {

            if (dp[mask] == -1)
                continue;

    
            int used = 0;
            int temp = mask;

            for (int slot = 0; slot < numSlots; slot++) {
                used += temp % 3;
                temp /= 3;
            }

            if (used == n)
                continue;

           
            for (int slot = 0; slot < numSlots; slot++) {

                int count = (mask / power3[slot]) % 3;

                if (count < 2) {

                    int newMask = mask + power3[slot];

                    int value = nums[used] & (slot + 1);

                    dp[newMask] = max(
                        dp[newMask],
                        dp[mask] + value
                    );
                }
            }
        }

        int answer = 0;

        for (int mask = 0; mask < totalStates; mask++) {
            answer = max(answer, dp[mask]);
        }

        return answer;
    }
};