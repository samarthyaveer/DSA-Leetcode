class Solution {
public:
    int score(vector<string>& cards, char x) {
        int xx = 0;
        int cnt1[10] = {};
        int cnt2[10] = {};

        for (const string& card : cards) {
            if (card[0] != x && card[1] != x)
                continue;

            if (card[0] == x && card[1] == x) {
                ++xx;
            }
            else if (card[0] == x) {
                ++cnt1[card[1] - 'a'];
            }
            else {
                ++cnt2[card[0] - 'a'];
            }
        }

        int s1 = 0, s2 = 0;
        int mx1 = 0, mx2 = 0;

        for (int i = 0; i < 10; ++i) {
            s1 += cnt1[i];
            s2 += cnt2[i];

            mx1 = max(mx1, cnt1[i]);
            mx2 = max(mx2, cnt2[i]);
        }
        auto calc = [](int s, int mx, int k) -> int {
            return min({
                (s + k) / 2,
                s - mx + k,
                s
            });
        };

        int ans = 0;
        
        for (int k = 0; k <= xx; ++k) {
            int left = calc(s1, mx1, k);
            int right = calc(s2, mx2, xx - k);

            ans = max(ans, left + right);
        }

        return ans;
    }
};