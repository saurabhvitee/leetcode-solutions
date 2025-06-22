class Solution {
public:
    vector<int> dp;

    int topDownDP(int lastIndex, vector<int>& nums) {
        if (lastIndex < 0) {
            return 0;
        }

        if (lastIndex == 0) {
            dp[0] = nums[0];
            return nums[0];
        }

        if (dp[lastIndex] != -1) {
            // we have already calculated result for this
            return dp[lastIndex];
        }

        int pick = nums[lastIndex] + topDownDP(lastIndex - 2, nums);
        int nonPick = topDownDP(lastIndex - 1, nums);

        // Memoization / caching
        dp[lastIndex] = max(pick, nonPick);

        return dp[lastIndex];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n, -1); // Correctly initialize here
        return topDownDP(n - 1, nums);
    }
};