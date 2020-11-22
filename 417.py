class Solution(object):
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        pacific = list()
        atlantic = list()
        
        nrow = len(matrix)
        ncol = len(matrix[0])
        
        visited = [[0 for i in range(ncol)] for j in range(nrow)]
        for i in range(ncol):
            pacific += self.dfs(matrix, visited, 0, i)
            
        for i in range(nrow):
            pacific += self.dfs(matrix, visited, i, 0)
            
        visited = [[0 for i in range(ncol)] for j in range(nrow)]
        for i in range(ncol):
            atlantic += self.dfs(matrix, visited, nrow-1, i)
            
        for i in range(nrow):
            atlantic += self.dfs(matrix, visited, i, ncol-1)
            
        res = [value for value in atlantic if value in pacific]
        
        return res 
            
            
            
    def dfs(self, matrix, visited, row, col):
        nrow = len(matrix)
        ncol = len(matrix[0])
        res = list()
        if visited[row][col] == 1:
            return res
        res.append([row, col])
        visited[row][col] = 1
        
        if row > 0:
            if matrix[row][col] <= matrix[row-1][col]:
                cand = self.dfs(matrix, visited, row-1, col)
                for lt in cand:
                    res.append(lt)
        
        if row < nrow-1:
            if matrix[row][col] <= matrix[row+1][col]:
                cand = self.dfs(matrix, visited, row+1, col)
                for lt in cand:
                    res.append(lt)
                
        if col > 0:
            if matrix[row][col] <= matrix[row][col-1]:
                cand = self.dfs(matrix, visited, row, col-1)
                for lt in cand:
                    res.append(lt)
                
        if col < ncol-1:
            if matrix[row][col] <= matrix[row][col+1]:
                cand = self.dfs(matrix, visited, row, col+1)
                for lt in cand:
                    res.append(lt)
        
        return res

matrix = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]

sol = Solution()
res = sol.pacificAtlantic(matrix)

print res
