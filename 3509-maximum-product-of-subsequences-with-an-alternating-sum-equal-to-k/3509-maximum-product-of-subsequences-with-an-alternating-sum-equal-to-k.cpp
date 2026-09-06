class Solution {
public:
    static constexpr int MAX_SUM = 3601;
    static constexpr int OFFSET = 1800;

    int maxProduct(vector<int>& nums, int k, int limit) {
        // No subsequence can have an alternating sum outside [-1800, 1800].
        if (k < -OFFSET || k > OFFSET)
            return -1;

        /*
            Product states:

            0 ... limit : exact product
            limit + 1   : product > limit (overflow state)

            dp[p][0] -> sums achievable with even-length subsequences
            dp[p][1] -> sums achievable with odd-length subsequences
        */
        using Bits = bitset<MAX_SUM>;
        using State = array<Bits, 2>;

        const int OVERFLOW = limit + 1;
        const int STATES = limit + 2;

        vector<State> dp(STATES);
        vector<State> next(STATES);

        for (int x : nums) {
            // Start with the option of NOT taking x.
            next = dp;

            for (int p = 0; p < STATES; ++p) {
                int newProduct;

                if (x == 0) {
                    // Any product becomes zero after multiplying by zero.
                    newProduct = 0;
                }
                else if (p == OVERFLOW) {
                    // A positive overflow product remains overflow.
                    newProduct = OVERFLOW;
                }
                else {
                    long long product = 1LL * p * x;

                    if (product <= limit)
                        newProduct = (int)product;
                    else
                        newProduct = OVERFLOW;
                }

                // Current subsequence has even length:
                // x goes to an even index => +x.
                if (dp[p][0].any()) {
                    next[newProduct][1] |= (dp[p][0] << x);
                }

                // Current subsequence has odd length:
                // x goes to an odd index => -x.
                if (dp[p][1].any()) {
                    next[newProduct][0] |= (dp[p][1] >> x);
                }
            }

            // Start a new subsequence containing only x.
            int product = (x <= limit ? x : OVERFLOW);

            // A single element has length 1 (odd parity).
            next[product][1].set(OFFSET + x);

            dp.swap(next);
        }

        // Search from the largest allowed product downward.
        for (int product = limit; product >= 0; --product) {
            int bit = OFFSET + k;

            if (dp[product][0][bit] ||
                dp[product][1][bit]) {
                return product;
            }
        }

        return -1;
    }
};