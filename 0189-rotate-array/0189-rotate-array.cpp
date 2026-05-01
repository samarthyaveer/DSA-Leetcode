class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int> temp = nums;
        int t = n-k, f = 0;
        for(int i=0; i<n; i++) {
            if(t<n) {
                nums[i] = temp[t];
                t++;
            }
            else {
                nums[i] = temp[f];
                f++;
            }
        }
    }
};