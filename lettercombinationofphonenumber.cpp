#include<queue>
#include <string>
struct indexstruct{
    string str = "";
    int index;
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        char basechar = 'a';
        int leng = digits.length();
        queue<indexstruct> structqueue;
        if (leng==0) {
            return result;
        }
        int charnum = 3;
        int sup = 0;
        if(digits[0] == '7' or digits[0] == '9') {
            charnum = 4;
        }
        if (digits[0] > '7') {
            sup=1;
        }
        for (int i=0;i<charnum;i++) {
            indexstruct is;
            is.str += char(basechar+int(digits[0]-'2')*3+i+sup);
            is.index = 0;
            if (is.index == leng-1) {
                result.push_back(is.str);
            } else {
                structqueue.push(is);
            }
        }
        
        while (!structqueue.empty()){
            indexstruct is = structqueue.front();
            structqueue.pop();
            int charnum = 3;
            if(digits[is.index+1] == '7' or digits[is.index+1] == '9') {
                charnum = 4;
            }
            int sup = 0;
            if(digits[is.index+1] > '7'){
                sup=1;
            }
            for(int i=0; i<charnum; i++) {
                indexstruct istmp;
                istmp.index = is.index+1;
                istmp.str = is.str + char(basechar+int(digits[istmp.index]-'2')*3+i+sup);

                if (istmp.index == leng-1) {
                    result.push_back(istmp.str);
                } else {
                    structqueue.push(istmp);
                }
            } 
        }
        return result;
        
    }
};