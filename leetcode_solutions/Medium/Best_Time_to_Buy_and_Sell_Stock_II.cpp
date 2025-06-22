class Solution {
public:
    int dp[100000][2]; // day, remaining k, holding (0/1)

    int solve(vector<int>& prices, int i, int holding) {
        if (i == prices.size()) return 0;

        if (dp[i][holding] != -1) return dp[i][holding];

        int doNothing = solve(prices, i + 1, holding);
        int doSomething = 0;

        if (holding) {
            // We can sell â gain money, and reduce available transactions
            doSomething = prices[i] + solve(prices, i + 1, 0);
        } else {
            // We can buy â pay money, but transaction count remains same
            doSomething = -prices[i] + solve(prices, i + 1, 1);
        }

        return dp[i][holding] = max(doNothing, doSomething);
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 0); 
        // start at day 0, unlimited transactions left, not holding
    }
};
