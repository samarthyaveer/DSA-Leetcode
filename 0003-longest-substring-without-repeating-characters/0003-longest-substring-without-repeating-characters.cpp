class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        unordered_map<char, int> lastIndex;
        int l = 0;
        int ans = 0;
        for(int r=0; r<n; r++) {
            if(lastIndex.find(s[r]) != lastIndex.end() && lastIndex[s[r]] >= l) {
                l = lastIndex[s[r]] + 1;
            }
            lastIndex[s[r]] = r;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};