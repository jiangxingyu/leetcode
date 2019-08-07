class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        bool start = false;
        bool isNega = false;
        for (int i=0; i<str.size(); i++) {
            if(str[i] == ' ') {
                if(start) {
                    break;
                }
                continue;
            } else if (str[i] == '-') {
                if(start) {
                    break;
                }
                start = true;
                isNega = true;
                
            } else if (str[i] == '+') {
                if(start) {
                    break;
                }
                start = true;

            }else if (str[i] >= '0' && str[i] <= '9') {
                start = true;                
                result *= 10;
                result += str[i] -'0';
                if (result > 2147483648) {
                     result = 2147483648;
                    break;
                }
            } else {
                if(!start) {
                    return 0;
                }
                break;
                
            }
        }
      
        if (isNega) {
            return -1*result;
        } else {
            if (result >= 2147483648) {
                result = 2147483647;
            }
            return result; 
        }
        return result;
    }
};