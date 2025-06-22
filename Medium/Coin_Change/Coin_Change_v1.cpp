class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialized the array from 0 to amount 
        // since amount is inclusive hence amount+1 is the size 
        // Initialized with INT_MAX since we need to calculate minimum coins 
        // to reach till amount 

        // Also amount here is state because we need to find answer for an amount 
        // so we will find answers for every amount in between 
        // at last return dp[amount]

        // since question is asking to return minimum coins for amount 


        vector<int> dp = vector<int>(amount+1, INT_MAX);
        dp[0] = 0;

        for(int i=1; i<=amount; i++){
            // We need to calculate answer for every amount 

            // I can arrive at this amount by all the coins so let's see 
            for(int j=0; j<coins.size(); j++){
                // If coin is bigger than amount we continue
                if(coins[j] > i)
                    continue;
                
                // Else let's update our answer 
                // I can arrive from previous reachable amount + 1 for current coin 
                if(dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }

        if(dp[amount] == INT_MAX)
            return -1;
            
        return dp[amount];
    }
};