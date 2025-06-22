class Solution {
public:
	int maxProfit(vector<int>& a) {
    	int ans=0;
    	int n=a.size();
    	if(n==0) return 0;
    	int mi=a[0];
    	for(int i=0;i<n;i++)
        {
        	ans=max(ans,a[i]-mi);
            mi=min(a[i],mi);
        }
    	return ans;
	}
};
