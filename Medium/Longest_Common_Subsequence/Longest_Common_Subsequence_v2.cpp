class Solution {
public:
    int bottomUpRecursiveDP(int i, int j, string& text1, string& text2,
                            vector<vector<int>>& dp) {
        if (i >= text1.size() or j >= text2.size()) {
            // since you can not find answer anymore if
            // any of the string is over
            return 0;
        }

        // Memoization 
        if(dp[i][j] != -1){
            // No need of calculation if already calculated 
            return dp[i][j];
        }

        int answerAtThisPoint = 0;

        if (text1[i] == text2[j]) {
            // increase both the indexes by adding 1
            // consider this as line
            answerAtThisPoint =
                1 + bottomUpRecursiveDP(i + 1, j + 1, text1, text2, dp);
        } else {
            // Hoping increasing 1st string might give me answer with 2nd as it is 
            // Hoping increasing 2nd string might give me answer with 1st as it is 
            answerAtThisPoint =
                max(bottomUpRecursiveDP(i + 1, j, text1, text2, dp),
                    bottomUpRecursiveDP(i, j + 1, text1, text2, dp));
        }

        dp[i][j] = answerAtThisPoint;
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp =
            vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1));
        return bottomUpRecursiveDP(0, 0, text1, text2, dp);
    }
};