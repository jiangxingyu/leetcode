class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int centerl = 0;
        int centerr = 0;
        int templ = 0;
        int tempr = 0;
        int resultl = 0;
        int resultr = 0;
        for (int i=0; i<len; i++) {
            centerl = i;
            centerr = i;
            while (centerl-1>=0 && centerr+1<len && s[centerl-1] == s[centerr+1]) {
                centerl--;centerr++;
            }
            templ = centerl;
            tempr = centerr;
            if (i+1<len && s[i] == s[i+1]) {
                centerl = i;
                centerr = i+1;
                while (centerl-1>=0 && centerr+1<len && s[centerl-1] == s[centerr+1]) {
                    centerl--;centerr++;
                }
            }
            if (centerr-centerl > tempr-templ) {
                templ = centerl;
                tempr = centerr;
            }
            if (tempr-templ > resultr-resultl) {
                resultr = tempr;
                resultl = templ;
            }
        }
        return s.substr(resultl, resultr-resultl+1);

    }
};