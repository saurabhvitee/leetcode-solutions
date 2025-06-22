class Solution {
public:
    // unordered_map<int, vector<int>> graph;
    vector<bool> seen;

    void dfs(int room, vector<vector<int>>& rooms) {
        seen[room] = true;

        for (int neighbor : rooms[room]) {
            if (!seen[neighbor]) {
                // seen[neighbor] = true; // safety check yet redundant.
                dfs(neighbor, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        seen = vector(n, false);

        // Since we already have rooms vector where you have neighbors info

        // Let's build the graph
        // for (int i = 0; i < n; i++) {
        //     int m = rooms[i].size();
        //     for (int j = 0; j < m; j++) {
        //         graph[i].push_back(rooms[i][j]);
        //     }
        // }

        dfs(0, rooms); // since 0th room is unlocked.

        // If all the nodes have been travelled then seen[i] = true for
        // everything. otherwise we will have few untravelled nodes.
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                // cout << "Node " << i << " is untraversed" << endl;
                return false;
            }
        }

        return true;
    }
};