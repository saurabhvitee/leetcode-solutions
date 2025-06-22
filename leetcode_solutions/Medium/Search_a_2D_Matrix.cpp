class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m*n; // Right is exclusive 

        while(left < right){
            // left < right since right is exclusive.

            // calculate mid 
            int mid = left + (right-left)/2;

            // calculate row and column.
            // divide by column and % by column 
            int row = mid/n;
            int col = mid%n;

            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] < target){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return false;
    }
};