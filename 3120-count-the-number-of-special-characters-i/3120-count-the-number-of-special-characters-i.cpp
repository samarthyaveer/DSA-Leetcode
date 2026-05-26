class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lowerCase(26, false), upperCase(26, false);
        int ans=0;
        
        for(char x : word) {
            if(x >= 'a' && x <= 'z') lowerCase[x-'a'] = true;
            else if(x >= 'A' && x <= 'Z') upperCase[x-'A'] = true;
        }

        for(int i=0; i<26; i++) if(lowerCase[i] && upperCase[i]) ans++;

        return ans;
    }
};