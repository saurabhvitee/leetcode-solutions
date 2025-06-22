class Solution {
    class Node {
    private:
        int row;
        int col;
        int minDistance;

    public:
        int getRow() { return row; }
        int getCol() { return col; }
        int getMinDistance() { return minDistance; }
        Node(int r, int c, int dist) {
            row = r;
            col = c;
            minDistance = dist;
        }
    };

public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool valid(int row, int col, int m, int n, vector<vector<char>>& grid) {
        return row >= 0 and col >= 0 and row < m and col < n;
    }

    int getFood(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<Node> q;

        // Find the * and start BFS from there.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    grid[i][j] = 'X';
                    q.push(Node(i, j, 0));
                    break;
                }
            }
            if (q.size() == 1) {
                break;
            }
        }

        int ans = INT_MAX;

        while (!q.empty()) {

            Node qFront = q.front();
            q.pop();

            int row = qFront.getRow();
            int col = qFront.getCol();
            int dist = qFront.getMinDistance();

            for (vector<int> direction : directions) {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];

                if (valid(nextRow, nextCol, m, n, grid)) {

                    // If it's simple free space, take this and move on.
                    // Mark this as done.
                    if (grid[nextRow][nextCol] == 'O') {
                        grid[nextRow][nextCol] = 'X';
                        q.push(Node(nextRow, nextCol, dist + 1));
                    }

                    // If you reach till food this is shortest path you can
                    // ever reach to any food.
                    if (grid[nextRow][nextCol] == '#') {
                        return dist + 1;
                        // Since we are using BFS below code is extraneous

                        // grid[nextRow][nextCol] = 'f';
                        // q.push(Node(nextRow, nextCol, dist+1));
                    }
                }
            }
        }
        return -1;
    }
};