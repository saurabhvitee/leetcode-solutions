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
        bool check = row >= 0 and col >= 0 and row < m and col < n;

        bool check2 = true;

        if(check){
            if(grid[row][col] == 'X'){
                check2 = false;
            }
        }

        return check and check2;
    }

    int getFood(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<Node> q;

        // Find the * and start BFS from there.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '*'){
                    grid[i][j] = 'X';
                    q.push(Node(i,j,0));
                    break;
                }
            }
            if(q.size() == 1){
                break;
            }
        }

        int ans = INT_MAX;

        while(!q.empty()){

            Node qFront = q.front();
            q.pop();

            int row = qFront.getRow();
            int col = qFront.getCol();
            int dist = qFront.getMinDistance();

            if(grid[row][col] == 'f'){
                ans = min(ans, dist);
            }

            for(vector<int> direction: directions){
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];

                if(valid(nextRow, nextCol, m, n, grid)){
                    cout << nextRow << " " << nextCol << endl;

                    if(grid[nextRow][nextCol] == 'O'){
                        grid[nextRow][nextCol] = 'X';
                        q.push(Node(nextRow, nextCol, dist+1));
                    }

                    if(grid[nextRow][nextCol] == '#'){
                        grid[nextRow][nextCol] = 'f';
                        q.push(Node(nextRow, nextCol, dist+1));
                    }
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};