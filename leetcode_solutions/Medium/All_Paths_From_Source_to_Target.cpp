class Solution {
public:
    void backtrack(int node, vector<int>& curr, vector<vector<int>>& ans, vector<vector<int>>& graph){
        int currSize = curr.size();

        if(curr[currSize-1] == graph.size()-1){
            // we are at n-1th node 
            // add it in our ans
            ans.push_back(curr);
        }

        // Loop over all the neighbors 
        for(int neighbor: graph[node]){
            // Starting node is 0 always 
            // Let's explore its neighbors 

            // add it in curr path 
            curr.push_back(neighbor);

            // explore further path with this neighbor 
            backtrack(neighbor, curr, ans, graph);

            // Unchoose current path and explore other neighbors 
            curr.pop_back();
        }
        
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curr;
        curr.push_back(0);
        backtrack(0,curr,ans,graph);
        return ans;
    }
};