class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& mat, int n) {
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        reverse(mat.begin(), mat.end());
        return mat;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        if(mat==target) return true;

        mat = rotate(mat, n);
        if(mat==target) return true;

        mat = rotate(mat, n);
        if(mat==target) return true;

        mat = rotate(mat, n);
        if(mat==target) return true;

        return false;
    }
};