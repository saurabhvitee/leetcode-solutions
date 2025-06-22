class Solution {
public:
    void backtrack(int currNum, int n, int k, int currSum, vector<int>& curr, vector<vector<int>>& ans){
        
        if(currSum == n and curr.size() == k){
            // We need combinations of a target sum with exact k numbers 
            // also sum should match to n.
            ans.push_back(curr);
        }

        for(int i=currNum; i<=9; i++){
            if(currSum + i <= n){
                curr.push_back(i);
                backtrack(i+1, n, k, currSum+i, curr,ans);
                curr.pop_back();
            }
        }

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(1, n, k, 0, curr, ans);
        return ans;
    }
};