class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = n - 1;
        string ans = "";
        
        while (i >= 0) {
            // 1. Skip any trailing or multiple spaces
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            
            // If i drops below 0 after skipping spaces, we are completely done
            if (i < 0) break;
            
            // 2. We hit a letter! Mark this as the end of the word (j)
            int j = i;
            
            // 3. Keep moving left until we hit a space (finding the start of the word)
            while (i >= 0 && s[i] != ' ') {
                i--;
            }
            
            // 4. Extract the word! 
            // It starts at i + 1, and its length is j - i
            if (!ans.empty()) {
                ans += " "; // Only add a space before the word if ans isn't empty
            }
            ans += s.substr(i + 1, j - i);
        }
        
        return ans;
    }
};