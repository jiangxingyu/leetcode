import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> substr = new HashSet<Character>();
        int maxlen = 1;
        int len = s.length();
        for (int i = 0; i<len; i++) {
            for (int j = i; j<i+maxlen; j++) {
                substr.add(s.CharAt(j));   
            }
            
            if (substr.size() == maxlen){
               for (int j = i+maxlen; j<len; j++) {
                   if (!substr.contains(s.CharAt(j))) {
                       substr.add(s.CharAt(j));
                       maxlen++;
                   } else {
                       break;
                   }
               }
            }
        }
        return maxlen;
        
//         Map<Character, Integer> location = new HashMap<Character, Integer>();
//         int len = s.length();
//         int start = 0;
//         int subLen = 0;
//         int tempStart = 0;
//         int templen = 0;
//         Integer templocation = 0;
//         for (int i = 0; i < len; i++) {
//             char index = s.charAt(i);
//             templocation = location.get(index);
//             if(templocation == null) {
//                 location.put(index, i); 
//             } else {
//                 templen = i-tempStart;
//                 if (templen > subLen) {
//                     subLen = templen;
//                     start = tempStart;
//                 }

//                 i = templocation;
//                 tempStart = templocation+1;
//                 templen = 1;
//                 location.clear();                
//             }
            
//         }
//         templen = len-tempStart;
//         if (templen > subLen) {
//             subLen = templen;
//             start = tempStart;
//         }
//         return subLen;
    }
}