class Solution {
public:
    vector<string> twoEditWords(vector<string>& que, vector<string>& dict) {
        vector<string> ans;

        for(int i=0; i<que.size(); i++) {
            for(int j=0; j<dict.size(); j++) {
                int diff = 0;
                for(int k=0; k<que[i].size(); k++) {
                    if(que[i][k] != dict[j][k]) diff++;
                }
                if(diff <= 2) {
                    ans.push_back(que[i]);
                    break;
                }
            }
        }
        return ans;
    }
};