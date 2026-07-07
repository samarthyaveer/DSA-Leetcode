class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int open = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(') {
                if(open > 0) res.push_back(s[i]);
                open++;
            }
            if(s[i]==')') {
                open--;
                if(open > 0) res.push_back(s[i]);
            }
        }
        return res;
    }
};