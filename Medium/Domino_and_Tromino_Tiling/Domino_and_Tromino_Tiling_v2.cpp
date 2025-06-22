class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp = vector<vector<int>>(1001, vector<int>(2, -1));  // -1 for unvisited

    int solve(int i, int n, bool previousGap) {
        if (i > n) return 0;
        if (i == n && !previousGap) return 1;

        if (dp[i][previousGap] != -1) return dp[i][previousGap];

        int res = 0;
        if (previousGap) {
            res = (solve(i + 1, n, false) + solve(i + 1, n, true)) % MOD;
        } else {
            res = (
                solve(i + 1, n, false) +
                solve(i + 2, n, false) +
                2LL * solve(i + 2, n, true) % MOD
            ) % MOD;
        }

        return dp[i][previousGap] = res;
    }

    int numTilings(int n) {
        return solve(0, n, false);
    }
};
