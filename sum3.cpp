#include<queue>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for (int i=0; i<len; i++) {
            if (nums[i] > 0) break;
            if (i > 0 and nums[i] == nums[i-1]) continue;
            int bej_index = i+1;
            int end_index = len-1;
            while(end_index > bej_index) {
                int sum = nums[i] + nums[bej_index] + nums[end_index];
                if (sum > 0) {
                    end_index--;
                } else if (sum < 0) {
                    bej_index++;
                } else {
                    result.push_back({nums[i],nums[bej_index],nums[end_index]});
                    end_index--;
                    bej_index++;
                    while(bej_index<end_index and nums[bej_index] == nums[bej_index-1]){
                        bej_index++;
                    }
                    while(end_index>bej_index and nums[end_index] == nums[end_index+1]){
                        end_index--;
                    }
                }
            }
        }
        return result;
    }
};