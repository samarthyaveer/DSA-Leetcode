class Solution {
public:

    int opChoice(vector<int>& nums, int l, int r) {
        if(l == r) return nums[l];

        int chooseL = nums[l] - opChoice(nums, l+1, r);
        int chooseR = nums[r] - opChoice(nums, l, r-1);

        return max(chooseL, chooseR);

    }

    bool predictTheWinner(vector<int>& nums) {
        return opChoice(nums, 0, nums.size()-1) >= 0;
    }
};