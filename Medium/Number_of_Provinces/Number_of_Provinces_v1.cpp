class Solution {
public:
    unordered_map<int, vector<int>> graph; // Graph
    vector<bool> seen;

    void dfs(int city) {
        // This to mark its neighbors with true
        // first of all mark the city with true
        seen[city] = true;

        // Now is the time for connected cities i.e. neighbors
        for(int neighborCity: graph[city]){
            if(!seen[neighborCity]){
                seen[neighborCity] = true;
                dfs(neighborCity); // Now recurse on its neighbor cities
            } 
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size(); // number of nodes / cities
        seen = vector(n+1, false);

        // Now let's create the graph.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    graph[i + 1].push_back(j + 1);
                    graph[j + 1].push_back(i + 1);
                    // since this is an undirected or
                    // bidirectional graph
                }
            }
        }

        int provinces = 0;
        // Now let's traverse in the nodes and count provinces.
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                // You have not seen this node so lets increase our provinces
                // and run DFS function DFS will mark all its neighbors with
                // true
                provinces++;
                dfs(i);
            }
        }

        return provinces;
    }
};