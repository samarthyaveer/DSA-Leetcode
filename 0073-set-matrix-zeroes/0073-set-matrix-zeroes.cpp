class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<int> rowMark(row, 0);
        vector<int> columnMark(column, 0);
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                if(matrix[i][j] == 0) {
                    rowMark[i] = 1;
                    columnMark[j] = 1;
                }
            }
        }

        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                if(rowMark[i] == 1 || columnMark[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};