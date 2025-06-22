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
        // vector<long long> dp = vector<long long>(n, 1LL * -1);
        // return bottomUpRecursionDP(questions, dp, 0, n);

        // Bottom up tabulation approach without recursion 
        // We need to start loop from back since current answer 
        // depends on j index = i + questions[i][1] + 1 (Skip questions)
        // At last we will return dp[0]

        vector<long long> dp = vector<long long>(n, 1LL * 0);

        // Base case
        // In this case dp[n-1] = questions[n-1][0]
        dp[n-1] = questions[n-1][0];

        for(int i=n-2; i>=0; i--){
            // Pick this and pick i + questions[i][1] + 1
            dp[i] = questions[i][0];
            if(i + questions[i][1] + 1 < n){
                // I can pick something from back 
                dp[i] += dp[i+questions[i][1]+1];
            }

            // Not pick and pick directly from previous 
            // Choice bw pick and non pick 
            dp[i] = max(dp[i], dp[i+1]);
        }

        return dp[0];
    }
};