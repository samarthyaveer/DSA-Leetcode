class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();

        for(int i=0; i<row; i++) {
            for(int j=i; j<column; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<row; i++) {
            for(int j=0; j<column/2; j++) {
                swap(matrix[i][j], matrix[i][column-1-j]);
            }
        }
    }
};