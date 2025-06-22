class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // We just need to count indegrees.

        vector<bool> indegrees(n, false);

        for (vector<int> edge : edges) {
            // We do not need to store vector<int> for indegrees
            // since we just care about if there are rows incoming to this node
            // (either 1 or many) or there are no rows incoming.
            indegrees[edge[1]] = true;
        }

        // Here we are picking all the nodes for which
        // indegree is false basically there are no rows/paths incoming
        vector<int> ans;
        int i = 0;
        for (bool indegree : indegrees) {
            if (!indegree) {
                ans.push_back(i);
            }
            i++;
        }

        return ans;
    }
};