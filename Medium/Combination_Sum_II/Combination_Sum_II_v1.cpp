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

            // This will insure that if two adjacent equal elements are present.
            // They will not be attributed at one location
            // For example 1,1,2,5, target=8
            // [1,2,5], [1,2,5] will be prevented as 1 is present at 0th index.

            // For example 1,1,2,5,6, target=8
            // [1,1,6] will not be prevented as 1 is present at different
            // indexes 0th and 1st.
            if (i > index and candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] + currSum <= target) {
                currPath.push_back(candidates[i]); // Choose this

                backtrack(candidates, i + 1, candidates[i] + currSum, target,
                          currPath, ans); // Explore

                currPath.pop_back(); // Unchoose this
            }
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currPath;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, 0, target, currPath, ans);
        return ans;
    }
};