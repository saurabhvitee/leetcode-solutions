class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool valid(int row, int col, vector<vector<int>> grid) {
        return row >= 0 and col >= 0 and row < grid.size() and
               col < grid[0].size();
    }

    int dfs(int row, int col, vector<vector<int>>& grid, int count) {
        grid[row][col] = 0;
        count++; // let's increase our count for connected components.

        for (auto direction : directions) {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];

            if (valid(nextRow, nextCol, grid) && grid[nextRow][nextCol]) {
                count = dfs(nextRow, nextCol, grid, count);
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
                    maxArea = max(maxArea, dfs(i, j, grid, 0));
                }
            }
        }
        return maxArea;
    }
};