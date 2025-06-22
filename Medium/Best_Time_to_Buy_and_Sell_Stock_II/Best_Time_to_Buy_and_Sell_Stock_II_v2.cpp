class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // Since if I pick any stock and tomorrow is a big loss in this stock 
        // they are asking maximum possibility not the reaility
        // Imagine I know the future 
        // So if tomorrow is loss I will sell it today itself.
        // If tomorrow is profit I will take it 

        // all profits are mine
        // all losses are not mine 

        int maximumProfit = 0;

        for(int i=1; i<n; i++){
            if(prices[i] > prices[i-1]){
                // There is some profit 
                // Okay in best case scneario I will take it 
                maximumProfit += (prices[i]-prices[i-1]);
            }
        }

        // Maximum we can earn this much profit 
        // cause we are pro 
        return maximumProfit;
    }
};