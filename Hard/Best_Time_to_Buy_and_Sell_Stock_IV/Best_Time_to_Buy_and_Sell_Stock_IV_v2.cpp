class Solution {
public:
    int topDownRecursiveApproach(int days, int transactions, int holding, int n, vector<int>& prices, vector<vector<vector<int>>>& dp){
        // Let's write base case
        // what if no transactions are allowed we can simply say no profit then 
        // what if there are no days left we can say profit is zero in that case 
        if(days >= n or transactions == 0){
            // This is to stop the recursion 
            return 0;
        }

        if(dp[days][transactions][holding] != -1)
            return dp[days][transactions][holding];

        // If k is infite means k>=n/2 
        // in that case all profits can be yours 
        // No further recursion 
        if(transactions >= (n/2)){
            int maxProfit = 0;
            for(int i=1; i<n; i++){
                if(prices[i] > prices[i-1]){
                    // It means there is some profit, take it 
                    maxProfit += (prices[i] - prices[i-1]);
                }
            }
            return maxProfit;
        }

        // Do nothing simply increase the day 
        int doNothing = topDownRecursiveApproach(days+1, transactions, holding, n, prices, dp);

        int doSomething = 0;

        // if you have holding already you can not buy 
        if(holding){
            // so you have to sell and move forward in life / days
            // Reduce the transaction since you have completed one after selling 
            // set holding to ZERO 
            doSomething = prices[days] + topDownRecursiveApproach(days+1, transactions-1, 0, n, prices, dp);
        }else{
            // Sorry my man you do not have any other option other than buy it 
            // Since you have bought you holdings will become 1
            // transaction will remain same as it is.
            doSomething = -prices[days] + topDownRecursiveApproach(days+1, transactions, 1, n, prices, dp);
        }   

        // Return maximum to the next day 
        dp[days][transactions][holding] = max(doNothing, doSomething);

        return dp[days][transactions][holding];
    }

    int maxProfit(int k, vector<int>& prices) {
        // Recursive approach 
        // Let's declare a dp array for memoization 
        // dp(days, at most k transaction, holding(0,1))
        // always use k+1 if at most k is asked in question 
        int n = prices.size();
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return topDownRecursiveApproach(0, k, 0, n, prices, dp);
    }
};