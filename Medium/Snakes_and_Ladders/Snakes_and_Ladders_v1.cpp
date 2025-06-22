class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        // Let's create a single dimension array with to store
        // row and column for every number.

        vector<pair<int, int>> gamePlay = vector<pair<int, int>>(n * n + 1);

        int label = 1;
        int reverseFlag = false;
        for (int row = n - 1; row >= 0; row--) {
            if (reverseFlag) {
                for (int col = n - 1; col >= 0; col--) {
                    gamePlay[label] = {row, col};
                    label++;
                    reverseFlag = false;
                }
                continue;
            }
            // start visit from last row cause thats how snake ladder board
            // designed
            for (int col = 0; col < n; col++) {
                gamePlay[label] = {row, col};
                reverseFlag = true;
                label++;
            }
        }

        // Now we will start from 1st location and play game.
        vector<int> dist =
            vector<int>(n * n + 1, -1); // Min distance to reach each node.
        queue<int> q;
        q.push(1);
        dist[1] = 0; // since you are starting from 1st

        while (!q.empty()) {
            int currBox = q.front();
            q.pop();

            if (currBox == n * n) {
                // If we reach in 4 steps it's useless to visit
                // rest of the board since it is BFS.
                return dist[currBox];
            }

            // Let's roll the dice make sure you don't jump out of the board.
            for (int next = currBox + 1; next <= min(currBox + 6, n * n);
                 next++) {

                auto [nextRow, nextCol] = gamePlay[next]; // move to next

                int destinationBox;
                if (board[nextRow][nextCol] == -1) {
                    destinationBox =
                        next; // Simple no snake no ladder move to next
                } else {
                    destinationBox =
                        board[nextRow][nextCol]; // Choose snake or ladder
                }

                if (dist[destinationBox] == -1) {
                    // We are visiting this node for the first time.
                    dist[destinationBox] = dist[currBox] + 1;
                    q.push(destinationBox);
                }
            }
        }

        return -1;
    }
};