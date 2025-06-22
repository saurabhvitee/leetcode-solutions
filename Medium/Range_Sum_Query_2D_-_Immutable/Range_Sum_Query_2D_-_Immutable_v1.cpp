class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0) return;
        sum = vector<vector<int>>(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                sum[i+1][j+1] = matrix[i][j] + sum[i][j+1] + sum[i+1][j] -sum[i][j];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] -sum[row1][col2+1] +sum[row1][col1];
    }
private:
    vector<vector<int>> sum;
};