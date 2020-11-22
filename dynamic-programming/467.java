class Solution {
    public int findSubstringInWraproundString(String p) {
        if (p.length() == 0) {
            return 0;
        }
        int[] sublen = new int[26];
        sublen[p.charAt(0)-'a'] = 1;
        int maxlen = 1;
        for (int i = 1; i < p.length(); ++i) {
            if (p.charAt(i) - p.charAt(i-1) == 1 || p.charAt(i-1) - p.charAt(i) == 25) {
                maxlen++;
            }
            else {
                maxlen = 1;
            }
            sublen[p.charAt(i) - 'a'] = Math.max(sublen[p.charAt(i) - 'a'], maxlen);
        }
        
        int ret = 0; 
        for (int i = 0; i < sublen.length; ++i) {
            ret += sublen[i];
        }
        return ret;
    }
}
