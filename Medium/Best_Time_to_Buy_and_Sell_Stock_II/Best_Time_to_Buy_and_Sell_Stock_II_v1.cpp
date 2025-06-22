class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int sum = 0;
        
        for(int i=0;i<(n-1);i++)
        {
            if(prices[i] < prices[i+1])
            {
                sum+=(prices[i+1]-prices[i]);
            }
        }
        return sum;
    }
};