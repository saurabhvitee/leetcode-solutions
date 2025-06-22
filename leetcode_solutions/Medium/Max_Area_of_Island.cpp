class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool valid(int row, int col, vector<vector<int>> grid) {
        return row >= 0 and col >= 0 and row < grid.size() and
               col < grid[0].size();
    }

    int dfs(int row, int col, vector<vector<int>>& grid, int count) {
        grid[row][col] = 0;

        for (auto direction : directions) {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];

            if (valid(nextRow, nextCol, grid) && grid[nextRow][nextCol]) {
                count = dfs(nextRow, nextCol, grid, count + 1);
                // Increase the count if you see connected island
            }
        }

        return count;
    }

    int bfs(int row, int col, vector<vector<int>>& grid, int count) {
        grid[row][col] = 0; // Mark node as visited before pushing into queue.
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto direction : directions) {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];

                if (valid(nextRow, nextCol, grid) && grid[nextRow][nextCol]) {
                    grid[nextRow][nextCol] = 0;
                    q.push({nextRow, nextCol});
                    count++;
                    // Increase the count if you see connected island
                }
            }
        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    // We have not seen this island first so let us do DFS/BFS
                    // on this

                    // Let us suppose there are no neighbors for this island
                    // So we will simply pass count as 1.
                    maxArea = max(maxArea, bfs(i, j, grid, 1));
                }
            }
        }
        return maxArea;
    }
};