class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    int ans = 0;

    void dfs(int node) {
        ans++;
        seen[node] = true;

        for (int neighbor : graph[node]) {
            if (!seen[neighbor]) {
                dfs(neighbor);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {

        seen = vector(n, false);

        for (vector<int> edge : edges) {
            // Since this is an undirected graph
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Let's mark restricted node already visited so if we arrive there
        // We do not count that node.
        for (int restrictedNode : restricted) {
            seen[restrictedNode] = true;
            graph[restrictedNode] = {}; // Broke further links
        }

        dfs(0);

        return ans;
    }
};