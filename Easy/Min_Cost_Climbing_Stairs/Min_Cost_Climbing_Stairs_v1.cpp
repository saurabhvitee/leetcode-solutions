class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // write bottom up approach for this initialize a dp array 
        int n = cost.size();
        vector<int> dp = vector<int>(n+1, 0);

        // initialize dp[0] and dp[1]
        dp[0] = 0;
        // dp[1] = min(cost[1], dp[0]);
        // dp[1] will always be zero because you can come at 0th index and 1th index for free
        dp[1] = 0;

        // Run a for loop for indexes greater than or equal to 2 
        for(int i=2; i<=n; i++){
            // Now at this point you can either come from i-2 in that case ans till there + cost[i-2]
            // or you can come from i-1 in that case ans till there + cost[i-1]
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        return dp[n];
    }
};