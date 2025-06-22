class Solution {
public:
    int recursiveSolution(int i, int j, int k, vector<vector<int>>& piles,
                          vector<vector<vector<int>>>& dp) {

        if(i >= piles.size()){
            return 0;
        }

        if(k == 0){
            return 0;
        }

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        int optionA = recursiveSolution(i+1, 0, k, piles, dp);

        // Choose from ith pile and jth index 
        int optionB = 0;
        if(j < piles[i].size())
            optionB = piles[i][j] + recursiveSolution(i, j+1, k-1, piles, dp);

        dp[i][j][k] = max(optionA, optionB);

        return dp[i][j][k];
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // find maximum j 
        int maxJ = INT_MIN;
        for(vector<int> eachPile: piles){
            int pileSize = eachPile.size();
            maxJ = max(maxJ, pileSize);
        }
        cout << maxJ << endl;
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(piles.size(), vector<vector<int>>(maxJ+1, vector<int>(k+1, -1)));
        return recursiveSolution(0, 0, k, piles, dp);
    }
};