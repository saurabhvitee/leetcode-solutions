class Solution {
public:
    long long bottomUpRecursionDP(vector<vector<int>>& questions,
                                  vector<long long>& dp, int index, int n) {
        if (index >= n) {
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        long long pick =
            questions[index][0] +
            bottomUpRecursionDP(questions, dp,
                                index + questions[index][1] + 1, n);
        long long notPick =
            bottomUpRecursionDP(questions, dp, index + 1, n);

        dp[index] = max(pick, notPick);

        return dp[index];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp = vector<long long>(n, 1LL * -1);
        return bottomUpRecursionDP(questions, dp, 0, n);

        // Initialize the dp array
        // vector<int> dp = vector<int>(n, 0);

        // dp[0] = questions[0][1]; // Since there is only one question

        // for(int i=1; i<n; i++){
        //     dp[i] = max(dp[i])
        // }

        // return dp[n-1];
    }
};