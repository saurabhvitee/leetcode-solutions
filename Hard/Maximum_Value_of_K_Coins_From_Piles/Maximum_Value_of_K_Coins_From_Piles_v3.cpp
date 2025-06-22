class Solution {
public:
    int recursiveSolution(int pileIndex, int coinRemaining,
                          vector<vector<int>>& piles, vector<vector<int>>& dp) {
        if (pileIndex >= piles.size()) {
            // All piles are over
            return 0;
        }

        if (coinRemaining == 0) {
            // you can not pick any more coins
            return 0;
        }

        if(dp[pileIndex][coinRemaining] != -1){
            return dp[pileIndex][coinRemaining];
        }

        // Skip this pile itself 
        // You have choosen 0 coins from here, next 5 coins from next piles.
        int ansTillThisPile = recursiveSolution(pileIndex+1, coinRemaining, piles, dp);

        // Choose x coins from this pile 
        // Choose remaining (coinRemaining-x) from next pile using recursion 
        int currPileSize = piles[pileIndex].size();
        int currSum = 0;

        for(int coinIndex=0; coinIndex < min(coinRemaining, currPileSize); coinIndex++){
            currSum += piles[pileIndex][coinIndex]; // Choose coins and make combinations 

            // You have choosen 1 coin from here, next 4 coins from next piles.
            // You have choosen 2 coins from here, next 3 coins from next piles
            // You have choosen 3 coins from here, next 2 coins from next piles
            // You have choosen 4 coins from here, next 1 coin from next piles 
            // You have choosen 5 coins from here, next 0 coins from next piles
            ansTillThisPile = max(ansTillThisPile, currSum + recursiveSolution(pileIndex+1, coinRemaining-coinIndex-1, piles, dp));
        }

        dp[pileIndex][coinRemaining] = ansTillThisPile;

        return dp[pileIndex][coinRemaining];
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp =
            vector<vector<int>>(piles.size(), vector<int>(k + 1, -1));
        return recursiveSolution(0, k, piles, dp);
    }
};