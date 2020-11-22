class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s2) < len(s1):
            return False
        
        kv = dict()
        for c in s1:
            if c not in kv:
                kv[c] = 0
            kv[c] += 1
            
        start, end = 0, 0
        
        while end < len(s1):
            if s2[end] in kv:
                kv[s2[end]] -= 1
            end += 1
                
        while end <= len(s2):
            if self.match(kv):
                return True
            if end == len(s2):
                break
                
            if s2[start] in kv:
                kv[s2[start]] -= 1
            if s2[end] in kv:
                kv[s2[end]] += 1
            end += 1
            start += 1
        return False
            
    def match(self, kv):
        for c in kv:
            if kv[c] != 0:
                return False            
        return True

sol = Solution()
sol.checkInclusion('ab', 'eidbaooo')

