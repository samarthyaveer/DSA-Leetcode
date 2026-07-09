class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        if(n <= 1) return strs[0];
        string ans = "";

        for(int i=0; i<m; i++) {
            char ref = strs[0][i];
            for(int j=1; j<n; j++) {
                if(i >= strs[j].size() || strs[j][i] != ref) return ans;
            }
            ans += ref;
        }
        return ans;
    }
};