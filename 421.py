class TrieNode(object):
    def __init__(self):
        self.child = [None, None]
    

class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        root = TrieNode()
        for num in nums:
            cur = root
            for i in range(31, -1, -1):
                bitval = self.getbit(num, i)
                if cur.child[bitval] is None:
                    cur.child[bitval] = TrieNode()
                cur = cur.child[bitval]
                
        res = 0                
        for num in nums:
            cur = root
            temp = 0
            for i in range(31, -1, -1):
                bitval = self.getbit(num, i)
                if cur.child[bitval^1] is not None:
                    temp += (1 << i)
                    cur = cur.child[bitval^1]
                else:
                    cur = cur.child[bitval]
            res = max(res, temp)
        
        return res
                
                
    def getbit(self, num, bitpos):
        return (num&(1<<bitpos))>>bitpos;
