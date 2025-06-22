#include <bits/stdc++.h>
class Solution {
public:
    void fun(vector <int> &nums , int i , vector<int> &sub , vector <vector <int> > &ans)
    {
        if(i==nums.size())
        {
            ans.push_back(sub);
            return;
        }
        fun(nums,i+1,sub,ans);
        sub.push_back(nums[i]);
        fun(nums,i+1,sub,ans);
        sub.pop_back(); //backtracking
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> ans;
        vector <int> sub;
        fun(nums,0,sub,ans);
        return ans;
    }
};