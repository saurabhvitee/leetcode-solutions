class Solution {
public:
    vector<vector<int>> directions = {{0,-1}, {-1,0}, {1,0}, {0,1}};

    bool backtrack(int row, int col, int index, string& word, vector<vector<char>>& board, vector<vector<bool>>& seen){
        if(index >= word.size()){
            // Since we are matching character by character 
            // When we are at index n means we have matched 
            // string from [0,n-1] so we can return true
            return true;
        }

        // Traverse to it's neighbors 
        for(vector<int> direction: directions){
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];

            // Check if valid
            if(nextRow>=0 and nextCol>=0 and nextRow<board.size() and nextCol<board[0].size()){

                // Check if unseen 
                if(!seen[nextRow][nextCol]){

                    // Now check if data is matching with word string for this index.
                    if(board[nextRow][nextCol] == word[index]){
                        seen[nextRow][nextCol] = true; // Choose this element
                        if(backtrack(nextRow, nextCol, index+1, word, board, seen)) return true; // backtrack
                        seen[nextRow][nextCol] = false; // Unchoose this element
                    }
                }
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // call backtrack function starting from each character 
        int m = board.size();
        int n = board[0].size();

        if (word.size() > m * n) return false; // early return

        unordered_map<char, int> boardCounter;
        for (const auto& row : board) {
            for (char ch : row) {
                boardCounter[ch]++;
            }
        }
        
        std::unordered_map<char, int> wordCounter;
        for (char ch : word) {
            wordCounter[ch]++;
        }
        
        for (const auto& entry : wordCounter) {
            if (entry.second > boardCounter[entry.first]) {
                return false;
            }
        }

        // Since this problem involves graph as well let's create a seen 2D array
        vector<vector<bool>> seen = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // There is no point in starting if first character is not matching 
                if(board[i][j] != word[0])
                    continue;

                // Mark this row,col as seen
                seen[i][j] = true; // Choose this element

                if(backtrack(i, j, 1, word, board, seen)) return true; // Backtrack 

                seen[i][j] = false; // Unchoose this element 


            }
        }
        return false;
    }
};