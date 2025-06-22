class Solution {
    class Node {
    private:
        int row;
        int col;
        int minDistance;
        int remainingK;

    public:
        int getRow() { return row; }
        int getCol() { return col; }
        int getMinDistance() { return minDistance; }
        int getRemainingK() { return remainingK; }

        Node(int r, int c, int dist, int k) {
            row = r;
            col = c;
            minDistance = dist;
            remainingK = k;
        }
    };

public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    // Check if position is within grid bounds
    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }

    int bfs(vector<vector<int>>& grid, int row, int col, int k) {
        int m = grid.size(), n = grid[0].size();

        // visited[row][col][k] = true means we have visited (row, col) with k obstacle removals left
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));

        queue<Node> q;
        q.push(Node(row, col, 0, k));
        visited[row][col][k] = true;

        while (!q.empty()) {
            Node node = q.front();
            q.pop();

            int r = node.getRow(), c = node.getCol();
            int dist = node.getMinDistance();
            int remainingK = node.getRemainingK();

            // If we reach the target cell
            if (r == m - 1 && c == n - 1) {
                return dist;
            }

            for (auto& dir : directions) {
                int newRow = r + dir[0], newCol = c + dir[1];

                if (valid(newRow, newCol, grid)) {
                    int newK = remainingK - grid[newRow][newCol];

                    // If we can eliminate the obstacle (or no obstacle), and havenât visited this state
                    if (newK >= 0 && !visited[newRow][newCol][newK]) {
                        visited[newRow][newCol][newK] = true;
                        q.push(Node(newRow, newCol, dist + 1, newK));
                    }
                }
            }
        }

        return -1; // No valid path found
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        return bfs(grid, 0, 0, k);
    }
};
