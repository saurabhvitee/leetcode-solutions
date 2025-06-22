class Solution {
public:
	int minSubArrayLen(int k, vector<int>& a) {
    	int i=0,j=0,sum=0,ans=INT_MAX;
    	int n= a.size();	 
    	while(j<n){
        	sum+=a[j];   
        	while(sum>=k){
             	ans=min(ans,j-i+1);
            	sum-=a[i];
            	++i;
        	}
        	++j;
    	}
   	return ((ans==INT_MAX)? 0 : ans);
   	 
	}
};
