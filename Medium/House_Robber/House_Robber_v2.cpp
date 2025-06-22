class Solution {
public:
    int topDownDP(int lastIndex, vector<int>& nums, vector<int>& dp) {
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

        // Pick the current element and move to next pick-able element which is
        // i+2th index
        int pick = nums[lastIndex] + topDownDP(lastIndex - 2, nums, dp);

        // Skip the current element and pick next pick-able element which is
        // i+1th index
        int nonPick = topDownDP(lastIndex - 1, nums, dp);

        // Memoization / caching
        dp[lastIndex] = max(pick, nonPick);

        return dp[lastIndex];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp = vector<int>(n, -1); // Correctly initialize here for
        // cache return topDownDP(n - 1, nums, dp);

        // Bottom up approach we will start from dp[0]
        // If there is only one element we will pick that element
        // If there are two element we will pick which one is greater element
        // so at dp[3] we will have a choice to make
        // dp[3] = max(dp[i]+dp[i-2], dp[i-1])

        vector<int> dp = vector<int>(n, 0); // Initialize with 0 for bottom up

        dp[0] = nums[0];

        if (n > 1) {
            dp[1] = max(nums[0], nums[1]);

            for (int i = 2; i < n; i++) {
                // Choose current element with i-2th element
                // Choose previous element and skip current element
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
            }
        }

        return dp[n - 1];
    }
};