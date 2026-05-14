class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mx = nums[n-1];
        if(n != mx+1 || nums[0] != 1 || nums[n-1] != nums[n-2]) return false;

        for(int i=1; i<n-1; i++) {
            if(nums[i]-nums[i-1] != 1) return false;
        }
        return true;
    }
};