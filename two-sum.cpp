#include<map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hs;
        int temp = 0;
        for (int i=0; i< nums.size(); i++) {
            temp = target - nums[i];
            if (hs.find(temp) != hs.end()) {
                return {hs[temp], i};
            }
            hs[nums[i]] = i;

        }
        return {};
    }
//     int binarySearch(vector<Cop> newnums, int num, int start) {
//         int min = start;
//         int max = newnums.size()-1;
//         int temp = -1;
//         while(max >= min) {
//             temp = (min+max) / 2;
//             if (num == newnums[temp].val) {
//                 return newnums[temp].pos;
//             } else if (num > newnums[temp].val) {
//                 min = temp+1;
//             } else {
//                 max = temp-1;
//             }
//         }
//         return -1;
//     }
    
//     vector<int> twoSum(vector<int>& nums, int target) {
        
//         vector<Cop> newnums;
//         for(int i = 0; i < nums.size(); i++) {
//             newnums.push_back({i, nums[i]});
//         }
//         std::sort(newnums.begin(), newnums.end(),
//                  [](Cop v1, Cop v2) {return v1.val < v2.val;});
//         vector<int> result;
//         int temp = 0;
//         for(int i = 0; i < newnums.size(); i++) {
//             temp = binarySearch (newnums, target-newnums[i].val, i+1);
//             if (temp != -1) {
//                 result.push_back(newnums[i].pos);
//                 result.push_back(temp);
//                 return result;
//             }
//         }
//         return result;
//     }
    
};