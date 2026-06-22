class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int lp = 1;
        int rp = 1;
        int mp = INT_MIN;
        for(int i=0; i<n; i++) {
            lp *= nums[i];
            rp *= nums[n-1-i];
            mp = max(max(lp, rp), mp);
            if(lp==0) lp = 1;
            if(rp==0) rp = 1;
        }
        return mp;
    }
};