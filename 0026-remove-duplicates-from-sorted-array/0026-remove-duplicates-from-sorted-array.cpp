class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i=1, j=0;
        ans[0] = nums[0];
        while(i<n) {
            if(nums[i] != ans[j]) {
                ans[j+1] = nums[i];
                j++;
            }
            i++;
        }
        for(int z=0; z<n; z++) {
            nums[z] = ans[z];
        }
        return j+1;
    }
};