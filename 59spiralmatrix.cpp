class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        for (int i=0;i<n;i++) {
            vector<int> row(n);
            result.push_back(row);
        }
        
        int max = n*n;
        int directions = 1;
        int currentx = 0;
        int currenty = 0;
        for (int i = 1;i <= max;i++) {
            result[currenty][currentx] = i;
            switch(directions) {
                case 1:
                    if (currentx == n-1 || result[currenty][currentx+1] != 0){
                        directions+=1;
                    } else {
                        currentx++;
                        break;
                    }
                case 2:
                    if (currenty == n-1 || result[currenty+1][currentx] != 0) {
                        directions+=1;
                    } else {
                        
                        currenty++;
                        break;
                    }
                case 3:
                    if (currentx == 0 || result[currenty][currentx-1] != 0) {
                        directions+=1;
                    } else {
                        
                        currentx--;
                        break;
                    }
                    
                case 4:
                     if (currenty == 0 || result[currenty-1][currentx] != 0) {
                        directions=1;
                        currentx++;
                    } else {
                        currenty--;
                        break;
                    }
 
            }
        }
        
        return result;
        
        
    }
};