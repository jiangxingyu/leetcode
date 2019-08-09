class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int temp = 0;
        int temp2;
        temp = num / 1000;
        for (int i=0; i< temp; i++) {
            result += 'M';  
        }
        string clist = "MDCLXVI";
        num = num % 1000;
        int index = 1;
        for (int k = 100; k>=1; k/=10) {
            
            temp = num / k;
            num = num % k;
            switch (temp){
                case 9:
                    result += clist[index+1];
                    result += clist[index-1];
                    break;
                case 4:
                    result += clist[index+1];
                    result += clist[index];
                    break;
                default: {
                    if (temp >= 5) {
                        result += clist[index];
                        for(int i=0; i<temp-5; i++) {
                            result += clist[index+1];
                        }
                    } else {
                       for(int i=0; i<temp; i++) {
                            result += clist[index+1];
                       } 
                    }
                }
            }
            index += 2;
        }
        return result;
    }
};