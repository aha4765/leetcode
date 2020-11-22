class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = list()
        return self.isvalid(s, stack)
        
    def isvalid(self, s, stack):
        if len(s) == 0:
            return len(stack) == 0
        
        if s[0] == '(':
            stack.append('(')
            if self.isvalid(s[1:], stack) is True:
              return True
            stack.pop()
        elif s[0] == ')':
            if len(stack) == 0 or stack[-1] != '(':
                stack.append(')')
                if self.isvalid(s[1:], stack) is True:
                  return True
                stack.pop()
            else:
                stack.pop()
                if self.isvalid(s[1:], stack) is True:
                  return True
                stack.append('(')
        else:
            if self.isvalid(s[1:], stack) is True:
                return True
            else:
                stack.append('(')
                if self.isvalid(s[1:], stack) is True:
                    return True
                stack.pop()
                if len(stack) == 0 or stack[-1] != '(':
                    stack.append(')')
                    if self.isvalid(s[1:], stack) is True:
                      return True
                    stack.pop()
                else:
                    stack.pop()
                    if self.isvalid(s[1:], stack) is True:
                      return True
                    stack.append('(')
            
sol = Solution()
ret = sol.checkValidString('(*))')
print ret
