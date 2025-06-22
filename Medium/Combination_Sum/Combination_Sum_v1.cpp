class Solution {
public:
    void backtrack(vector<int>& candidates, int index, int currSum, int target,
                   vector<int>& currPath, vector<vector<int>>& ans) {

        if (currSum == target) {
            ans.push_back(currPath);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // We need to pass index here cause next time we do not want 

            if (candidates[i] + currSum <= target) {
                currPath.push_back(candidates[i]); // Choose this

                backtrack(candidates, i, candidates[i] + currSum, target, currPath, ans); // Explore

                currPath.pop_back(); // Unchoose this
            }
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currPath;
        backtrack(candidates, 0, 0, target, currPath, ans);
        return ans;
    }
};