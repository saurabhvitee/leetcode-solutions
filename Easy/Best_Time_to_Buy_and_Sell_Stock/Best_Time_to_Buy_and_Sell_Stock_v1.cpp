class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <int> arr;
        arr.push_back(0);
        int sum=0;
        int maxs=0;
        for(int i=1;i<n;i++){
            arr.push_back(prices[i]-prices[i-1]);
            sum=sum+arr[i];
            if(sum<0){
                sum=0;
            }
            maxs = max(sum,maxs);
        }
        return maxs;
        
    }
};