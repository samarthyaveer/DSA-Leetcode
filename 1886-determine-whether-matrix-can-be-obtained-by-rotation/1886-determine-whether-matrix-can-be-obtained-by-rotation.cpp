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

    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target, int n) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        if(isEqual(mat, target, n)) return true;

        mat = rotate(mat, n);
        if(isEqual(mat, target, n)) return true;

        mat = rotate(mat, n);
        if(isEqual(mat, target, n)) return true;

        mat = rotate(mat, n);
        if(isEqual(mat, target, n)) return true;

        return false;
    }
};