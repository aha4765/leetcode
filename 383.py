class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        char2count = dict()
        for i in range(len(magazine)):
            if magazine[i] not in char2count:
                char2count[magazine[i]] = 1
            else:
                char2count[magazine[i]] += 1
                
        for i in range(len(ransomNote)):
            if ransomNote[i] not in char2count:
                return False
            else:
                char2count[ransomNote[i]] -= 1
                if char2count[ransomNote[i]] < 0:
                    return False
        return True
        
