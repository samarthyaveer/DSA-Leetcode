class Solution {
public:
    bool rotateString(string s, string goal) {
        string t = s;
        int n = t.length();
        if(goal.length() != n) return false;
        for(int i=0; i<n; i++) {
            char temp = t[0];
            for(int j=0; j<n-1; j++) {
                t[j] = t[j+1];
            }
            t[n-1] = temp;
            if(t == goal) return true;
        }
        return false;
    }
};