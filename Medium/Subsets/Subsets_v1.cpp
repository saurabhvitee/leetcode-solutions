class Solution {
public:
	
	void fun(vector<int>&a,int i,vector<int>&sub,vector<vector<int> >&ans)
	{
	if(i==a.size())
	{
    	ans.push_back(sub);
    	return ;
	}
    	fun(a,i+1,sub,ans);
    	sub.push_back(a[i]);
    	fun(a,i+1,sub,ans);
    	sub.pop_back();
	}
	vector<vector<int>> subsets(vector<int>& a) {
    	vector<vector<int> >ans;
    	vector<int> sub;
    	fun(a,0,sub,ans);
        	return ans;
   	 
	}
};
