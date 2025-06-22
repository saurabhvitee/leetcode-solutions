class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1},  {1, 0},  {0, 1},
                                      {1, 1},  {-1, -1}, {-1, 1}, {1, -1}};

    bool valid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size();
    }

    int bfs(int row, int col, vector<vector<int>>& grid) {
        grid[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int shortestPath = 1;
        // Since we need to count number of nodes and not edges.
        // and (0,0) is a valid node

        while (!q.empty()) {
            // To count levels remember what we have done in trees.
            // We need to process one level, increase our count.
            // to process one level we need to process all the elements in queue
            // in one go. calculate queue size and run loop

            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto [row, col] = q.front();
                q.pop();

                if (row == grid.size() - 1 && col == grid[0].size() - 1) {
                    // We need to check that grid[n-1][n-1] is also accessible
                    return shortestPath;
                }

                for (vector<int> direction : directions) {
                    int nextRow = row + direction[0];
                    int nextCol = col + direction[1];

                    if (valid(nextRow, nextCol, grid) &&
                        !grid[nextRow][nextCol]) {
                        grid[nextRow][nextCol] = 1;
                        q.push({nextRow, nextCol});
                    }
                }
            }
            // Once one level is complete I am increasing my level.
            shortestPath++;
        }
        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        // One early exit we can implement by checking if grid[m][n] is reachable or not
        // This can save us some extra computation

        int m = grid.size();
        int n = grid[0].size();


        if (!grid[0][0] and !grid[m-1][n-1])
            return bfs(0, 0, grid);
        return -1;
    }
};