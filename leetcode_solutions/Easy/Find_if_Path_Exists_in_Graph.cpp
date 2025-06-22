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

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        seen = vector(n, false);

        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            // Bi directional undirected graph
        }

        dfs(source); // start from the source

        // Check if you have seen that node or not
        // If you start traversing from source node, are you reaching
        // destination ?
        return seen[destination];
    }
};