class Solution {
    class Node {
    private:
        int row;
        int col;
        int dist;
        int lives;

    public:
        Node(int r, int c, int d, int l) {
            row = r;
            col = c;
            dist = d;
            lives = l;
        }

        int getRow() { return row; }
        int getCol() { return col; }
        int getDist() { return dist; }
        int getLives() { return lives; }
    };

public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // We will keep track of with what power you have seen this Node
        // If you have seen this node with greater lives remaining 
        // No need to process this again.
        // Otherwise process this node again cause this might be helpful in future. 
        vector<vector<int>> seen = vector(m, vector<int>(n, INT_MIN));

        // I will put everything in queue
        // Additional factor - remaining lives so I can destroy obstacles.
        // In case if BFS does not give me answer. 
        // There has to be some differentiating factor 

        queue<Node> q;
        // Let's push 0,0 in this
        q.push(Node(0,0,0,k));

        // BFS traversal with some hack 
        while(!q.empty()){
            Node qFront = q.front();
            q.pop();

            int row = qFront.getRow();
            int col = qFront.getCol();
            int dist = qFront.getDist();
            int remainingLives = qFront.getLives();

            // Check if you have reached till end node. 
            if(row == m-1 and col == n-1){
                // If at all there is any possible path.
                return dist; // cause BFS will always takes you with shortest path.
            }

            // Now we need to enter in BFS 
            // Important condition is for example if you have seen current node 
            // with higher remaining lives already then no need to process this shit again 

            // This condition is very important otherwise we will be visiting all nodes 
            // no matter that node is useless to us or not. 
            
            if(seen[row][col] >= remainingLives){
                continue; // Since you have already seen this node before 
                // that too with better power 
                // Note you have already added condition which node we do not want to visit.
            }

            // This might be the better path with more remaining lives.
            // So lets update this
            seen[row][col] = remainingLives;

            for(vector<int> direction: directions){
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];

                // Check if valid
                if(nextRow>=0 and nextCol>=0 and nextRow<m and nextCol<n){
                    // Since this is better node anyway we need to push it.

                    // calculate new remaining life.
                    int remainingLifeAferProcessingThisNode = remainingLives - grid[nextRow][nextCol];
                    // It will be reduced by 1 if there is an obstacle.

                    if(remainingLifeAferProcessingThisNode >= 0){
                        q.push(Node(nextRow, nextCol, dist+1, remainingLifeAferProcessingThisNode));
                    }
                }
            }
        }
        return -1;
    }
};