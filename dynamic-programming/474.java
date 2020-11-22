class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] matrix = new int[m+1][n+1];
        for (int i = 0; i < strs.length; ++i) {
            int ones = 0, zeros = 0;
            for (int j = 0; j < strs[i].length(); ++j) {
                if (strs[i].charAt(j) == '0') {
                    zeros++;
                }
                else if (strs[i].charAt(j) == '1') {
                    ones++;
                }
            }
            
            for (int z = m; z >= 0; --z) {
                for (int o = n; o >= 0; --o) {
                    if (z >= zeros && o >= ones) {
                        matrix[z][o] = Math.max(matrix[z][o], 1+matrix[z-zeros][o-ones]);
                    }
                }
            }
        }
        return matrix[m][n];
    }
}
