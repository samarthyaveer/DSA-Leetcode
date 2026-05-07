class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n), suffMin(n);

        prefMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        vector<int> ans(n);

        int start = 0;
        int curMax = nums[0];

        for (int i = 0; i < n - 1; i++) {

            curMax = max(curMax, nums[i]);

            if (prefMax[i] <= suffMin[i + 1]) {

                for (int j = start; j <= i; j++) {
                    ans[j] = curMax;
                }

                start = i + 1;

                if (start < n)
                    curMax = nums[start];
            }
        }

        curMax = nums[start];
        for (int i = start; i < n; i++) {
            curMax = max(curMax, nums[i]);
        }

        for (int i = start; i < n; i++) {
            ans[i] = curMax;
        }

        return ans;
    }
};