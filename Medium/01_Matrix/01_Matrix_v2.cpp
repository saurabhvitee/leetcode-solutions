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
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<bool>> seen;

    bool valid(int row, int col, int m, int n) {
        return row >= 0 and col >= 0 and row < m and col < n;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // Initially all seen nodes are false.
        seen = vector(m, vector<bool>(n, false));

        // Initialize queue
        queue<Node> q;

        // Traverse and enqueue all the ZERO's
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j]) {
                    // If node is zero lets push this in queue
                    q.push(Node(i, j, 0));
                    seen[i][j] = true;
                }
            }
        }

        // Traverse in queue and update shortest distance

        while (!q.empty()) {
            // Pop the first element and traverse to its neighbors.
            Node queueFront = q.front();
            q.pop();

            int row = queueFront.getRow(), col = queueFront.getCol(),
                minDistance = queueFront.getMinDistance();

            for (vector<int> direction : directions) {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];

                if (valid(nextRow, nextCol, m, n) and !seen[nextRow][nextCol]) {
                    // If this element has not seen before
                    seen[nextRow][nextCol] = true;
                    mat[nextRow][nextCol] =
                        minDistance + 1; // BFS always use shortest path.
                    q.push(Node(nextRow, nextCol, minDistance + 1));
                }
            }
        }

        return mat;
    }
};