class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // We need 2 indexes to track both of the string 
        // One for each string 
        // we will only increase our both the indexes if 
        // element is same at ith and jth index 
        // otherwise take max from neighbors 

        // why take max from neighbors ?
        // ace,ab (ans here is 1)=> ace, abc 
        // ac, abc (ans here is 2) => ace, abc
        // what should be answer for ace, abc = max of above mentioned two neighbors 

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        // Since we would need neighbors even for first row and first column 

        // dp[i][j] is the answer for (i-1, j-1) indexes 
        // since 0 based index 
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1] == text2[j-1]){
                    // If this is equal then increase dp[i][j] by 1
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    // As explained take max of neighbors if this is not same 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};