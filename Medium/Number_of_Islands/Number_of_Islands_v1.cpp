class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(int row, int col, vector<vector<char>>& grid) {
        grid[row][col] = '0'; // this denotes node is done.
        // We do not need seen vector here we are doing it in place

        for (auto direction : directions) {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];

            if (nextRow >= 0 and nextRow < grid.size() and nextCol >= 0 and
                nextCol < grid[0].size()) {
                // If it is valid set of combination then only we will proceed
                // with DFS.
                if (grid[nextRow][nextCol] == '1') {
                    dfs(nextRow, nextCol, grid);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int numberOfIslands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    // If this is a valid island then please carefully increase the isLand number 
                    // Also mark all its neighbors inplace '0'
                    numberOfIslands++;
                    dfs(i, j, grid);
                }
            }
        }

        return numberOfIslands;
    }
};