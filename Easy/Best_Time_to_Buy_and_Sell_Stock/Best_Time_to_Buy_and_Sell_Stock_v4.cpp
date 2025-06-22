class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> prefix;
        for(int i=1;i<n;i++)
        {
            int diff = prices[i] - prices[i-1];
            prefix.push_back(diff);
        }
        
        int l = prefix.size();
        int cs = 0;
        int ms = INT_MIN;
        for(int i=0;i<l;i++)
        {
            cs = cs + prefix[i];
            if(cs < 0)
            {
                cs = 0;
            }
            
            if(cs > ms)
            {
                ms = cs;
            }
            
        }
        if(ms != INT_MIN)
        return ms;
        else
            return 0;
        
    }
};