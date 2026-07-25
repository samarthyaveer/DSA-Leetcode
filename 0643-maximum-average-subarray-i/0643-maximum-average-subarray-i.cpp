class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double s = 0;
        for(int i=0; i<k; i++) s += nums[i];
        double avg = s/k;

        for(int i=k; i<nums.size(); i++) {
            s -= nums[i-k];
            s += nums[i];
            avg = max(avg, s/k);
        }
        return avg;
    }
};