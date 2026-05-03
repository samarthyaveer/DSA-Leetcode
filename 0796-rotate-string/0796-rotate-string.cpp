class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();

        if (n != m) return false;

        for (int i=0; i<n; i++) {
            char first = s[0];
            for (int j=0; j<n-1; j++) {
                s[j] = s[j+1];
            }
            
            s[n - 1] = first;
            if (s == goal) return true;
        }
        return false;
    }
};