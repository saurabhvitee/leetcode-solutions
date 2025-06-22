class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        queue<vector<int>> q;                  // Store Node(row, col, distance)
        q.push({entrance[0], entrance[1], 0}); // Enqueue Entrance point
        maze[entrance[0]][entrance[1]] = '+';  // Mark this visited.

        int ans = INT_MAX;

        while (!q.empty()) {
            vector<int> qFront = q.front();
            q.pop();

            int row = qFront[0], col = qFront[1], dist = qFront[2];

            if (row == m - 1 or col == n - 1 or row == 0 or col == 0) {
                if (row == entrance[0] and col == entrance[1]) {
                    // Do nothing
                } else {
                    ans = min(ans, dist);
                }
            }

            for (vector<int> direction : directions) {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];

                if (nextRow >= 0 and nextCol >= 0 and nextRow < m and
                    nextCol < n) {
                    // If this is a valid pair let's check seen and wall.
                    if (maze[nextRow][nextCol] != '+') {
                        maze[nextRow][nextCol] = '+';
                        q.push({nextRow, nextCol, dist + 1});
                    }
                }
            }
        }

        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};