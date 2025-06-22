class Solution {
public:
    int topDownDP(int n, vector<int>& dp){
        if(n < 0){
            return 0; // You are skipping top 
            // this is not valid way to count 
        }

        if(n == 0){
            return 1; // One valid way to reach here at top
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = topDownDP(n-1, dp) + topDownDP(n-2, dp);

        return dp[n];
    }
    int climbStairs(int n) {
        // vector<int> dp = vector<int>(n+1, -1);
        // return topDownDP(n, dp);

        // Tabulation implementation 

        vector<int> dp = vector<int>(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            // since I can come at this by 1 step or 2 steps 
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};