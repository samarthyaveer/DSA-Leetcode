class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int a = 0, b = 0;
        while(a<m && b<n) {
            if(nums1[a] == nums2[b]) return nums1[a];
            if(nums1[a] < nums2[b]) a++;
            else b++;
        }
        return -1;
    }
};