class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        if(n==0)
        {
            return false;
        }
        int m = matrix[0].size();
        
        int start = matrix[n-1][m-1];
        
        int ri = 0;
        int ci = m-1;
        int flag = 0;
        while(ri<n && ci>=0)
        {
            if(matrix[ri][ci] == target)
            {
                flag = 1;
                break;
            }
            else if(matrix[ri][ci] < target)
            {
                ri++;
            }
            else
            {
                ci--;
                //start = matrix[ri][ci];
            }
        }
        if(flag == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
};