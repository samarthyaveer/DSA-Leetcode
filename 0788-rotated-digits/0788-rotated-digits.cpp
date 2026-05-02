class Solution {
public:
    int rotatedDigits(int n) {
        int good = 0;

        for(int i=1; i<=n; i++) {
            int t1 = i;
            bool valid = true, diff = false;

            while(t1>0) {
                int t2 = t1%10;
                if(t2==3 || t2==4 || t2==7) {
                    valid = false;
                    break;
                }
                if(t2==2 || t2==5 || t2==6 || t2==9) diff = true;
                t1 /= 10;
            }
            
            if(valid && diff) good++;
        }

        return good;
    }
};