class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int max1=0, max2=0;
        int a=0;
        while(a<n-1) {
            if(colors[a] != colors[n-1]){
                max1 = n-1-a;
                break;
            }
            a++;
        }
        a=n-1;
        while(a>0) {
            if(colors[a] != colors[0]){
                max2 = a;
                break;
            }
            a--;
        }
        return max(max1, max2);
    }
};