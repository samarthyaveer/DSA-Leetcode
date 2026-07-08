class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size(), n = needle.size();
        vector<int> lps(n, 0);
        int pre = 0, suf = 1;

        while(suf < n) {
            if(needle[pre] == needle[suf]) {
                lps[suf] = pre+1;
                pre++;
                suf++;
            }
            else {
                if(pre == 0) {
                    lps[suf] = 0;
                    suf++;
                }
                else pre = lps[pre-1];
            }
        }
        int i=0, j=0;
        while(i<h) {
            if(haystack[i] == needle[j]) {
                i++; j++;
            }
            if(j==n) return i-j;
            else if(i<h && haystack[i] != needle[j]) {
                    if(j!=0) j=lps[j-1];
                    else i++;
            }
        }
        return -1;
    }
};