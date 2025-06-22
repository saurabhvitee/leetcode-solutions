class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<int>> redGraph;
        unordered_map<int, vector<int>> blueGraph;

        static constexpr int RED = 0;
        static constexpr int BLUE = 1;

        for (vector<int> redEdge : redEdges) {
            redGraph[redEdge[0]].push_back(redEdge[1]);
        }

        for (vector<int> blueEdge : blueEdges) {
            blueGraph[blueEdge[0]].push_back(blueEdge[1]);
        }

        vector<int> ans = vector(n, INT_MAX);

        // We need 2D bool array for 2 colors
        vector<vector<bool>> seen =
            vector<vector<bool>>(n, vector<bool>(2, false));

        // We need a queue with (Node, Color, Distance)
        queue<vector<int>> q;

        seen[0][RED] = true;
        q.push({0, RED, 0}); // Let's push red edge (Node, Color, Distance)

        seen[0][BLUE] = true;
        q.push({0, BLUE, 0}); // push blue edge (Node, Color, Distance)

        // Let's traverse every node and update minimum shortest path.
        while (!q.empty()) {
            vector<int> qFront = q.front();
            q.pop();

            int node = qFront[0], color = qFront[1], dist = qFront[2];

            // For every node update the shortest path
            // Since it is BFS so let's check
            ans[node] = min(ans[node], dist);

            // Traverse to it's neighbors in both the graphs.

            // Red Graph only if current color is BLUE
            if (color == BLUE) {
                for (int neighbor : redGraph[node]) {
                    if (!seen[neighbor][RED]) {
                        seen[neighbor][RED] = true;
                        // If you have not seen this node with red color push it
                        // into queue
                        q.push({neighbor, RED, dist + 1});
                    }
                }
            }

            // Blue Graph only if current color is RED.
            if (color == RED) {
                for (int neighbor : blueGraph[node]) {
                    if (!seen[neighbor][BLUE] and seen[node][RED]) {
                        seen[neighbor][BLUE] = true;
                        // if you haven't seen this node with blue color push it
                        // into queue
                        q.push({neighbor, BLUE, dist + 1});
                    }
                }
            }
        }

        replace(ans.begin(), ans.end(), INT_MAX, -1);

        return ans;
    }
};