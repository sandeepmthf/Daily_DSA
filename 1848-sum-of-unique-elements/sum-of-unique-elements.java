class Solution {
    public int sumOfUnique(int[] nums) {
        Arrays.sort(nums);

        int ans = 0;
        int i = 0;

        while (i < nums.length) {
            int j = i;

            while (j < nums.length && nums[j] == nums[i]) {
                j++;
            }

            if (j - i == 1) {
                ans += nums[i];
            }

            i = j;
        }

        return ans;
    }
}