class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, double> mp{{'b',0}, {'a',0}, {'l',0}, {'o',0}, {'n',0}};

        for(char c : text) {
            if(c=='b' || c=='a' || c=='n') mp[c] += 1;
            if(c=='l' || c=='o') mp[c] += 0.5;
        }
        int m = INT_MAX;
        for(auto &i : mp) {
            if(i.second < m) m = i.second;
        }
        return m;
    }
};