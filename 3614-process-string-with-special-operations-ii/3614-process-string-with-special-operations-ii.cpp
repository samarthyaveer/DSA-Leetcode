class Solution {
public:
    char processStr(string s, long long k) {
        long long length = 0;

        for(char ch: s) {
            switch(ch) {
                case '*':
                    if(length > 0)
                        length--;
                    break;
                case '#':
                    length *= 2;
                    break;
                case '%':
                    break;
                default:
                    length++;
            }
        }

        if(k >= length)
            return '.';

        for(int i=s.size()-1; i>=0; i--) {
            switch(s[i]) {
                case '*':
                    length++;
                    break;
                case '#':
                    length /= 2;
                    k = (k >= length)? k - length: k;
                    break;
                case '%':
                    k = length - k - 1;
                    break;
                default:
                    length--;
            }
            if(k == length)
                return s[i];
        }

        return '.';
    }
};