class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        int col0 = 1;
        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j>0) matrix[0][j] = 0;
                    else col0 = 0;
                }
            }
        }

        for(int i=row-1; i>0; i--) {
            for(int j=column-1; j>0; j--) {
                if(matrix[0][j]==0 || matrix[i][0]==0) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=column-1; j>0; j--) if(matrix[0][0]==0) matrix[0][j] = 0;
        for(int i=row-1; i>=0; i--) if(col0==0) matrix[i][0] = 0;
    }
};