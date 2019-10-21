class Solution {
    public boolean isPalindrome(int x) {
        String str = String.valueOf(x);
        int len = str.length();
        for (int i=0;i<len;i++) {
            if (str.charAt(i) == str.charAt(len-1-i)) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
}