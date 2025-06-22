class Solution {
public:
    int recursiveSolution(int i, int j, int k, vector<vector<int>>& piles,
                          vector<vector<vector<int>>>& dp) {

        if(i >= piles.size()){
            return 0;
        }

        if(j >= piles[i].size()){
            return 0;
        }

        if(k == 0){
            return 0;
        }

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        // Choose from ith pile and jth index 
        int optionA = piles[i][j] + recursiveSolution(i, j+1, k-1, piles, dp);
        int optionB = piles[i][j] + recursiveSolution(i+1, 0, k-1, piles, dp);
        int optionC = recursiveSolution(i+1, 0, k, piles, dp);

        dp[i][j][k] = max(optionA, max(optionB, optionC));

        return dp[i][j][k];
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        // find maximum i and j
        // since array is not symmetrical 

        int maxI = piles.size();
        int maxJ = INT_MIN;
        for(vector<int> eachPile: piles){
            int pileSize = eachPile.size();
            maxJ = max(maxJ, pileSize);
        }
        
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(maxI, vector<vector<int>>(maxJ, vector<int>(k+1, -1)));
        return recursiveSolution(0, 0, k, piles, dp);
    }
};