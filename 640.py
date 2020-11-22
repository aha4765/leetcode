class Solution(object):
    def solveEquation(self, equation):
        """
        :type equation: str
        :rtype: str
        """
        lex = equation.split('=')[0]
        rex = equation.split('=')[1]
        
        xnum = 0
        nsum = 0
        flag = 1
        num = 0
        
        i = 0
        while i < len(lex):
            if lex[i] == 'x':
                if num == 0:
                    xnum += flag
                else:
                    xnum += flag*num
                i += 1
                num = 0
            elif lex[i] == '+':
                flag = 1
                i += 1
                num = 0
            elif lex[i] == '-':
                flag = -1
                i += 1
                num = 0
            else:
                num = 0
                while i < len(lex) and lex[i] >= '0' and lex[i] <= '9':
                    num *= 10
                    num += ord(lex[i]) - ord('0')
                    i += 1
                if i == len(lex) or lex[i] != 'x':
                    nsum += flag*num
                    
        i = 0
        flag = -1
        while i < len(rex):
            if rex[i] == 'x':
                if num == 0:
                    xnum += flag
                else:
                    xnum += flag*num
                i += 1
                num = 0
            elif rex[i] == '+':
                flag = -1
                i += 1
                num = 0
            elif rex[i] == '-':
                flag = 1
                i += 1
                num = 0
            else:
                num = 0
                while i < len(rex) and rex[i] >= '0' and rex[i] <= '9':
                    num *= 10
                    num += ord(rex[i]) - ord('0')
                    i += 1
                if i == len(rex) or rex[i] != 'x':
                    nsum += flag*num
                    
        if xnum == 0:
            if nsum == 0:
                return "Infinite solutions"
            else:
                return "No solution"
        else:
            return "x=" + str(-1*nsum/xnum)

sol = Solution()
sol.solveEquation("0x=0")
