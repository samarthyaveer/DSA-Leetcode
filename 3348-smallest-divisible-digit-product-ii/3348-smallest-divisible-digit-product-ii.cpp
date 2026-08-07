#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    const int fact2[10] = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
    const int fact3[10] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
    const int fact5[10] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    const int fact7[10] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};

    int min_digits(long long c2, long long c3, long long c5, long long c7) {
        c2 = max(0LL, c2);
        c3 = max(0LL, c3);
        c5 = max(0LL, c5);
        c7 = max(0LL, c7);

        int count = c7 + c5 + (c3 / 2) + (c2 / 3);
        int r2 = c2 % 3;
        int r3 = c3 % 2;

        if (r2 == 0 && r3 == 0) {
        } else if (r2 == 2 && r3 == 1) {
            count += 2;
        } else {
            count += 1;
        }
        return count;
    }

    string greedy_fill(int len, long long c2, long long c3, long long c5, long long c7) {
        string res = "";
        res.reserve(len);
        for (int k = 0; k < len; ++k) {
            int rem_len = len - 1 - k;
            for (int d = 1; d <= 9; ++d) {
                long long nc2 = c2 - fact2[d];
                long long nc3 = c3 - fact3[d];
                long long nc5 = c5 - fact5[d];
                long long nc7 = c7 - fact7[d];
                if (min_digits(nc2, nc3, nc5, nc7) <= rem_len) {
                    res += to_string(d);
                    c2 = nc2;
                    c3 = nc3;
                    c5 = nc5;
                    c7 = nc7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        long long temp_t = t;
        long long cnt2 = 0, cnt3 = 0, cnt5 = 0, cnt7 = 0;
        
        while (temp_t % 2 == 0) { temp_t /= 2; cnt2++; }
        while (temp_t % 3 == 0) { temp_t /= 3; cnt3++; }
        while (temp_t % 5 == 0) { temp_t /= 5; cnt5++; }
        while (temp_t % 7 == 0) { temp_t /= 7; cnt7++; }

        if (temp_t > 1) return "-1";

        int n = num.length();
        int first_zero = n;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        vector<long long> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        for (int i = 0; i < first_zero; ++i) {
            int d = num[i] - '0';
            p2[i + 1] = p2[i] + fact2[d];
            p3[i + 1] = p3[i] + fact3[d];
            p5[i + 1] = p5[i] + fact5[d];
            p7[i + 1] = p7[i] + fact7[d];
        }

        if (first_zero == n) {
            if (p2[n] >= cnt2 && p3[n] >= cnt3 && p5[n] >= cnt5 && p7[n] >= cnt7) {
                return num;
            }
        }

        int start_i = min(n - 1, first_zero);
        for (int i = start_i; i >= 0; --i) {
            int start_d = (i < first_zero) ? (num[i] - '0' + 1) : 1;
            for (int d = start_d; d <= 9; ++d) {
                long long rem2 = cnt2 - p2[i] - fact2[d];
                long long rem3 = cnt3 - p3[i] - fact3[d];
                long long rem5 = cnt5 - p5[i] - fact5[d];
                long long rem7 = cnt7 - p7[i] - fact7[d];

                int rem_len = n - 1 - i;
                if (min_digits(rem2, rem3, rem5, rem7) <= rem_len) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    ans += greedy_fill(rem_len, rem2, rem3, rem5, rem7);
                    return ans;
                }
            }
        }

        int req_len = min_digits(cnt2, cnt3, cnt5, cnt7);
        int target_len = max(n + 1, req_len);
        return greedy_fill(target_len, cnt2, cnt3, cnt5, cnt7);
    }
};