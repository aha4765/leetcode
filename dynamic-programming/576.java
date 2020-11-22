class Solution {
    public int findPaths(int m, int n, int N, int i, int j) {
        int[][][] mem = new int[m][n][N+1];
        for (int tempi = 0; tempi < m; ++tempi) {
            for (int tempj = 0; tempj < n; ++tempj) {
                for (int k = 0; k <= N; ++k) {
                    mem[tempi][tempj][k] = -1;
                }
            }
        }
        return helper(m, n, N, i, j, mem);
    }
    
    private int helper(int m, int n, int N, int i, int j, int[][][] mem) {
        int M = 1000000007;
        if (i <0 || j < 0 || i >= m || j >= n) {
            return 1;
        }
        else if (N == 0) {
            return 0;
        }
        if (mem[i][j][N] != -1) {
            return mem[i][j][N];
        }
        mem[i][j][N] = (((helper(m, n, N-1, i-1, j, mem)%M + helper(m, n, N-1, i+1, j, mem))%M + helper(m, n, N-1, i, j-1, mem))%M + helper(m, n, N-1, i, j+1, mem))%M;
        return mem[i][j][N];
    }
    
}

class Solution {
    public int findPaths(int m, int n, int N, int i, int j) {
        int M = 1000000000 + 7;
        int[][] mem = new int[m][n];        
        int[][] tmp = new int[m][n];
        mem[i][j] = 1;
        int count = 0;
        for (int step = 1; step <= N; ++step) {
            for (int bi = 0; bi < m; bi++) {
                for (int bj = 0; bj < n; bj++) {
                    if (bi == 0)
                        count = (count + mem[bi][bj])%M;
                    if (bi == m-1)
                        count = (count + mem[bi][bj])%M;
                    if (bj == 0)
                        count = (count + mem[bi][bj])%M;
                    if (bj == n-1)
                        count = (count + mem[bi][bj])%M;
                    tmp[bi][bj] = ((((bi > 0 ? mem[bi-1][bj] : 0) + (bi < m-1 ? mem[bi+1][bj] : 0))%M + (bj > 0 ? mem[bi][bj-1] : 0))%M + (bj < n-1 ? mem[bi][bj+1] : 0))%M;
                }
            }
            int[][] swap;
            swap = mem;
            mem = tmp;
            tmp = swap;
        }
        return count;
    }
}
