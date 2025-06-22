class Solution {
public:
	
	void fun(vector<int>&a,int i,vector<int>&sub,set<vector<int> >&ans)
	{
	if(i==a.size())
	{
        ans.insert(sub);
   //     ms.insert(ans);
    	return ;
	}
    fun(a,i+1,sub,ans);
    sub.push_back(a[i]);
    fun(a,i+1,sub,ans);
    sub.pop_back();
	}

	vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(),a.end());
        set <vector<int>> ans;
        vector<vector<int>> anss;
        vector<int> sub;
    	fun(a,0,sub,ans);
        for(auto c:ans){
            anss.push_back(c);
        }
    	
        return anss;
	}
};
