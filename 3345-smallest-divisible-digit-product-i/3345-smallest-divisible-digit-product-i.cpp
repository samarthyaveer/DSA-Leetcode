class Solution {
public:
    bool div(int n, int t) {
        long long product = 1;
        while(n) {
            product *= n%10;
            n /= 10;
        }
        return product%t == 0;
    }
    int smallestNumber(int n, int t) {
        int ans = n;
        while(!div(ans, t)) ans++;
        return ans;
    }
};