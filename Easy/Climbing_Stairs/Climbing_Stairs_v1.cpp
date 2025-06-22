class Solution {
public:
    int topDownDP(int n, vector<int>& dp){
        if(n < 0){
            return 0; // You are skipping top 
            // this is not valid way to count 
        }

        if(n == 0){
            dp[0] = 1;
            return 1; // One valid way to reach here at top
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = topDownDP(n-1, dp) + topDownDP(n-2, dp);

        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp = vector<int>(n+1, -1);
        return topDownDP(n, dp);
    }
};