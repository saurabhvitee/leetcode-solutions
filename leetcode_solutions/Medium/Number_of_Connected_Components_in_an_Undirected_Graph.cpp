class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;

    void dfs(int node) {
        seen[node] = true;

        for (int neighbor : graph[node]) {
            if (!seen[neighbor]) {
                dfs(neighbor);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        seen = vector(n, false);

        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]); // undirected graph
        }

        int ans = 0; // Increase our answer only if there are connected components. 
        
        for (int node = 0; node < n; node++) {
            if (!seen[node]) {
                ans++;
                dfs(node);
            }
        }

        return ans;
    }
};