class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
       
        n = len(matrix)
        m = len(matrix[0])
        
        first_row_has_zero = False
        first_col_has_zero = False

        # Check if first row has any zero
        for j in range(m):
            if matrix[0][j] == 0:
                first_row_has_zero = True
                break

        # Check if first column has any zero
        for i in range(n):
            if matrix[i][0] == 0:
                first_col_has_zero = True
                break

        # Use first row and column as markers
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        # Zero out cells based on markers
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        # Zero out the first row if needed
        if first_row_has_zero:
            for j in range(m):
                matrix[0][j] = 0

        # Zero out the first column if needed
        if first_col_has_zero:
            for i in range(n):
                matrix[i][0] = 0

        