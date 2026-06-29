class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=1, j=0;
        while(i<n) {
            if(nums[i] != nums[j]) {
                nums[j+1] = nums[i];
                j++;
            }
            i++;
        }
        return j+1;
    }
};