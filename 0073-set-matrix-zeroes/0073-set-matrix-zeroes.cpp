class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        int MARKER = 1e9+7;
        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                if(matrix[i][j] == 0) {
                    int k1 = 0, k2 = 0;
                    while(k1!=row) {
                        if(matrix[k1][j] != 0) matrix[k1][j] = MARKER;
                        k1++;
                    }
                    while(k2!=column) {
                        if(matrix[i][k2] != 0) matrix[i][k2] = MARKER;
                        k2++;
                    }
                }
            }
        }

        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                if(matrix[i][j] == MARKER) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};