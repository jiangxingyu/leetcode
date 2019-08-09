class Solution {
public:
    bool isMatch(string s, string p) {
        s = " "+s;
        p = " "+p;
        int len1 = s.size();
        int len2 = p.size();
        int **group = new int* [len2+1];
        for (int i=0; i<len2; i++) {
            group[i] = new int [len1+1];
            for (int j=0; j<=len1; j++) {
                group[i][j] = 0;
            }
        }
        group[0][0] = 1;
        for (int i=1; i<len2; i++) {
            for (int j=0; j<len1; j++) {
                
                    if (j>0&&group[i][j-1] == 1) {
                        if (p[i] == '*' && (p[i-1] == s[j] || p[i-1] == '.')) {
                            group[i][j] = 1;
                            continue;
                        }
                    } 
                    if (group[i-1][j] == 1) {
                        if (p[i] == '*') {
                            group[i][j] = 1;
                            continue;
                        }
                    }
                    if (j>0&&group[i-1][j-1] == 1) {
                        if (p[i] == s[j] || p[i] == '.') {
                            group[i][j] = 1;
                            continue;
                        }
                    }
                    if (p[i] == '*' && i>1) {
                        group[i][j] = group[i-2][j];
                    }
                
            }
        }
        // for (int i=0;i<len2;i++) {
        //     for (int j=0;j<len1;j++) {
        //         cout << group[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if (group[len2-1][len1-1] == 1) {
            return true;
        }
        
        return false;
    }
};