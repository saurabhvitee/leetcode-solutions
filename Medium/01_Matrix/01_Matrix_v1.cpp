class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Initialize your dp array with same matrix
        vector<vector<int>> dp(mat.begin(), mat.end());

        // First pass from top to bottom
        // update minNeighbor and add 1 into that

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // You can arrive dp[i][j] either from dp[i-1][j] or dp[i][j-1]

                int minNeighbor =
                    m * n; // since maximum can be m*n for any element.

                // Skip if dp[i][j] = 0;
                if (dp[i][j] == 0) {
                    continue; // we do not have to do anything in this case.
                }

                if (i - 1 >= 0) {
                    minNeighbor = min(dp[i - 1][j], minNeighbor);
                }

                if (j - 1 >= 0) {
                    minNeighbor = min(dp[i][j - 1], minNeighbor);
                }

                dp[i][j] = minNeighbor + 1;
            }
        }

        // Second pass from bottom to top
        // update minNeighbor and add 1 to that
        // compare it with previous dp[i][j] which we have calculated from top
        // to bottom pass choose whatever is minimum.
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (dp[i][j] == 0) {
                    continue;
                }

                int minNeighbor = m * n;

                if (i + 1 < m) {
                    minNeighbor = min(minNeighbor, dp[i + 1][j]);
                }

                if (j + 1 < n) {
                    minNeighbor = min(minNeighbor, dp[i][j + 1]);
                }

                dp[i][j] = min(dp[i][j], minNeighbor + 1);
            }
        }
        return dp;
    }
};