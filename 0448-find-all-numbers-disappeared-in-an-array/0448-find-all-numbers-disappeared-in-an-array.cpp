class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> mp;
        for(int i=0; i<n; i++) {
            mp[i+1] = false;
        }
        for(int i=0; i<n; i++) {
            mp[nums[i]] = true;
        }
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(mp[i+1]==false) ans.push_back(i+1);
        }
        return ans;
    }
};