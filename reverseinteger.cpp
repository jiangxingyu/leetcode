class Solution {
public:
    int reverse(int x) {
        int thisnum = 0;
        int finalnum = 0;
        int maxint = INT_MAX/10;
        int minint = INT_MIN/10;
        while (x != 0) {
            thisnum = x % 10;
            if (maxint < finalnum || minint > finalnum) {
                return 0;
            }
            finalnum *= 10;
            finalnum += thisnum;
            x/=10;
        }
        return finalnum;
    }
};