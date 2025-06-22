class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<string> directedEdges; // **_Reduced memory usage here_**
    vector<bool> seen;
    int ans = 0;
    int n;

    void dfs(int node) {
        seen[node] = true;

        for (auto neighbor : graph[node]) {
            if (!seen[neighbor]) {
                if (directedEdges.count(
                        to_string(node) + "," +
                        to_string(neighbor))) { // **_Direction check_**
                    ans++;
                }
                dfs(neighbor);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        this->n = n;
        seen = vector<bool>(n, false);

        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
            directedEdges.insert(
                to_string(conn[0]) + "," +
                to_string(conn[1])); // **_Store directed edge_**
        }

        dfs(0);
        return ans;
    }
};
