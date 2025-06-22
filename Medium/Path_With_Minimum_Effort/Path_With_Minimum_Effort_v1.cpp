class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {0,-1}, {1,0}, {0,1}};

    bool isValid(int row, int col, int m, int n){
        return row>=0 and col>=0 and row<m and col<n;
    }

    bool checkPossibility(int effort, vector<vector<int>>& heights){
        // is it possible to reach till end with this effort. 
        int m = heights.size();
        int n = heights[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> visited = vector<vector<int>>(m, vector<int>(n, false));
        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            if(row == m-1 and col == n-1)
                return true; 
            
            // let's go to neighbors only if absolute difference with neighbor 
            // is within limit (effort here) otherwise we will say it is not possible 

            for(vector<int> direction: directions){
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];

                if(isValid(nextRow, nextCol, m, n)){
                    // only process if it is a valid node.
                    if(abs(heights[nextRow][nextCol] - heights[row][col]) <= effort){
                        // only process this node if effort for this node is within limit.
                        if(!visited[nextRow][nextCol]){
                            // only process this node if unvisited till now.
                            visited[nextRow][nextCol] = true;
                            q.push(make_pair(nextRow, nextCol));
                        }
                    }
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0; 
        int right = 1000000; // since maximum difference can be 1e6

        // Let's apply binary search on this solution space.
        // we will find minimum effort (diff) till where it is possible.
        while(left <= right){
            int mid = left + (right-left)/2;

            if(checkPossibility(mid, heights)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};