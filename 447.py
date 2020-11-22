class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        npoints = len(points)
        dist = [[0 for i in range(npoints)] for j in range(npoints)]
        
        for i in range(npoints):
            for j in range(npoints):
                dist[i][j] = pow((points[i][0]-points[j][0]), 2) + pow((points[i][1]-points[j][1]), 2)
                
        res = 0
        for src in range(npoints):
            samedist = dict()
            for cand in range(npoints):
                if src != cand:
                    if dist[src][cand] not in samedist:
                        samedist[dist[src][cand]] = 1
                    else:
                        samedist[dist[src][cand]] += 1
                        
            for _ in samedist:
                res += self.permutation(samedist[_])
                
        return res
                
        
    def permutation(self, n):
        res = 1
        while n > 0:
            res *= n
            n -= 1
        return res

a=[[0,0], [1, 0], [2,0]]
sol = Solution()
print sol.numberOfBoomerangs(a)
