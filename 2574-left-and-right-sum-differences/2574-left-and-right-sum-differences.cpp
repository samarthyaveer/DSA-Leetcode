class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rightSum = 0, leftSum = 0;
        for(int x : nums) rightSum += x;
        for(int i=0; i<nums.size(); i++) {
            rightSum -= nums[i];
            int diff = abs(rightSum - leftSum);
            leftSum += nums[i];
            nums[i] = diff; 
        }
        return nums;
    }
};