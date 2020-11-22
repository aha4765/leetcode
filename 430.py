# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next

        self.child = child

class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        self.dfs(head)
        return head
        
    def dfs(self, head):
        cur = head
        tail = None
        while cur != None:
            if cur.child == None:
                tail = cur
                cur = cur.next
            else:
                temphead = cur.child
                temptail= self.dfs(temphead)
                cur.child = None
                temptail.next = cur.next
                if cur.next != None:
                    cur.next.pre = temptail
                cur.next = temphead
                temphead.pre = cur
                tail = temptail
                cur = temptail.next
        return tail
            
n1 = Node(1, None, None, None)        
n2 = Node(2, None, None, None)        
n3 = Node(3, None, None, None)        
n4 = Node(4, None, None, None)        

n1.next = n2
n2.pre=n1
n2.next=n3
n2.child=n4
n3.pre=n2

sol = Solution()
sol.flatten(n1)

cur=n1
while cur != None:
    print cur.val
    cur = cur.next
