class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int mod = 2e9;

        vector<vector<long long >> dp(m+1, vector<long long>(n+1, 0));

        for(int i=0; i<=m; i++){
            dp[i][0] = 1;
        }

        for(int i=0; i<=n; i++){
            dp[0][i] = 1;
        }

        for(int i=1;i<=m;i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        for(int i=0;i<=m;i++){
            for(int j=0; j<=n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        } 
        return (int)dp[m-1][n-1];     
    }
};