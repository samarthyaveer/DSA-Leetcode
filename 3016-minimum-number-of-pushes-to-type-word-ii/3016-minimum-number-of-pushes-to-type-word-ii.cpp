class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for(char c : word) {
            freq[c-'a']++;
        }
        sort(freq.begin(), freq.end());
        int ans = 0, count = 0;
        for(int i=25; i>=0; i--) {
            if(freq[i] == 0) break;

            if(count<8) ans += freq[i];
            else if(count>7 && count<16) ans += 2 * freq[i];
            else if(count>15 && count<24) ans += 3 * freq[i];
            else ans += 4 * freq[i];

            count++;
        }

        return ans;
    }
};