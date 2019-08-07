class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_size = 0;
        int head = 0;
        int tail = height.size()-1;
        int temp_size = 0;
        int temp = 0;
        while(head != tail) {
            if (height[head] >= height[tail]) {
                temp = height[tail];
                temp_size = (tail - head) * height[tail];
                do {
                    --tail;
                } while(temp >= height[tail] && head != tail);
            } else {
                temp = height[head];
                temp_size = (tail - head) * height[head];
                do {
                    ++head;
                } while(temp >= height[head] && head != tail);
            }
            if (temp_size>max_size) {
                max_size = temp_size;
            }
        }
        
        return max_size;
        
    }
};