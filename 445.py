#Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l1 = self.reverse(l1)
        l2 = self.reverse(l2)
        
        add = 0
        tail = None
        while l1 != None or l2 != None or add != 0:
            val1 = 0
            val2 = 0
            if l1 == None:
                val1 = 0
            else:
                val1 = l1.val
                l1 = l1.next
                
            if l2 == None:
                val2 = 0
            else:
                val2 = l2.val
                l2 = l2.next
                
            tempnode = ListNode((add + val1 + val2)%10)
            add = (add + val1 + val2)/10
            tempnode.next = tail
            tail = tempnode
            
        return self.reverse(tail)
            
                
    def reverse(self, l1):
        pre = None
        cur = l1
        nex = l1.next
        
        while cur != None:
            cur.next = pre
            pre = cur
            cur = nex
            if nex != None:
                nex = nex.next
        
        return pre

n1 = ListNode(7)
n2 = ListNode(2)
n3 = ListNode(4)
n4 = ListNode(3)
n5 = ListNode(5)
n6 = ListNode(6)
n7 = ListNode(4)

n1.next = n2
n2.next = n3
n3.next = n4
n5.next = n6
n6.next = n7

sol = Solution()
res = sol.addTwoNumbers(n1, n5)
