class Solution {
public:
    int ans = 0;

    void backtrack(int row, int n, unordered_set<int>& diagonals, unordered_set<int>& antidiagonals, unordered_set<int>& columns){
        if(row == n){
            // Basecase if we are reaching till Nth row 
            // that means we have put queens in all the rows from [0,n-1]
            // This is one way of solving N queens problem
            ans++;
            return;
        }

        // Traverse in every column for this particular row 
        for(int col=0; col<n; col++){ 

            // Very important concept here 
            // row-col would be same for everything in diagonals 
            // row+col would be same for everything in antidiagonals
            int currDiagonal = row-col; 
            int currAntiDiagonal = row+col; 

            // Check if you can place a queen at this location --> (row,col)
            // Obviously row is unique so we need to check in columns, antidiagonals, diagonals

            if(columns.contains(col) or diagonals.contains(currDiagonal) or antidiagonals.contains(currAntiDiagonal)){
                // You can not put any queen here 
                // Better luck next time
                continue;
            }
            
            // Add in HashSets of cols, diagonals and antidiagonals
            columns.insert(col);
            diagonals.insert(currDiagonal);
            antidiagonals.insert(currAntiDiagonal);

            // Move to next row with recursion
            backtrack(row+1, n, diagonals, antidiagonals, columns);

            // Pruning - Pop back - backtracking
            columns.erase(col);
            diagonals.erase(currDiagonal);
            antidiagonals.erase(currAntiDiagonal);
        }

        return;
    }


    int totalNQueens(int n) {
        unordered_set<int> diagonals, antidiagonals, columns;
        // We will start from first row, place the queen
        // Let backtrack function does his job by moving to next row
        // Pop from (first_row, first_col) so next time recurse function will pick (first_row, first_col+1)
        backtrack(0, n, diagonals, antidiagonals, columns);
        return ans;
    }
};