class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
       
        n = len(matrix)
        m = len(matrix[0])

        # Initialize (n+1)x(m+1) flag matrix with 1s
        flags = [[1] * (m + 1) for _ in range(n + 1)]

        # Step 1: Mark the rows and columns where zeros are found
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    flags[i + 1][0] = 0    # Mark row i
                    flags[0][j + 1] = 0    # Mark column j

        # Step 2: Apply the markings to the original matrix
        for i in range(n):
            for j in range(m):
                if flags[i + 1][0] == 0 or flags[0][j + 1] == 0:
                    matrix[i][j] = 0

        