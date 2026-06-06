class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rightSum = 0, leftSum = 0;
        for(int x : nums) rightSum += x;
        vector<int> answer;
        for(int i=0; i<nums.size(); i++) {
            int diff = abs(rightSum - nums[i] - leftSum);
            answer.push_back(diff);
            rightSum -= nums[i];
            leftSum += nums[i]; 
        }
        return answer;
    }
};