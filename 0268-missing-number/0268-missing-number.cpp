class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int realSum = (n*(n+1))/2;
        int currSum = 0;
        for(int x : nums) currSum += x;
        return realSum - currSum;
    }
};