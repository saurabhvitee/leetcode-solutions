class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // write bottom up approach for this initialize a dp array 
        int n = cost.size();
        // vector<int> dp = vector<int>(n+1, 0);

        // // initialize dp[0] and dp[1]
        // dp[0] = 0;
        // // dp[1] = min(cost[1], dp[0]);
        // // dp[1] will always be zero because you can come at 0th index and 1th index for free
        // dp[1] = 0;

        // // Run a for loop for indexes greater than or equal to 2 
        // for(int i=2; i<=n; i++){
        //     // Now at this point you can either come from i-2 in that case ans till there + cost[i-2]
        //     // or you can come from i-1 in that case ans till there + cost[i-1]
        //     dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        // }

        // return dp[n];

        // Optimize space complexity since we just need 2 states 
        int prev2 = 0; // Same as dp[0]
        int prev1 = 0; // Same as dp[1]

        // Here we will take <= n because this is very important 
        // you need to reach at nth stair not n-1th stair 
        
        for(int i=2; i<=n; i++){
            // Now at current level you can arrive from prev2 or prev1 
            // If you are coming from prev2 + add value at that stair 
            // If you are coming from prev1 + add value at that stair 

            int curr = min(prev2 + cost[i-2], prev1 + cost[i-1]);
            prev2 = prev1;
            prev1 = curr;
        }

        // Last executed curr will be stored here 
        return prev1;
    }
};