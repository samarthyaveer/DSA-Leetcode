class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int a=0, b=0, c=n-1;
        while(b<=c) {
            if(nums[b] == 0) {
                swap(nums[a], nums[b]);
                a++;
                b++;
            }
            else if(nums[b] == 1) b++;
            else {
                swap(nums[b], nums[c]);
                    c--;
            }
        }
    }
};