# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if root == None:
            return 0
        return self.helper(root, sum) + self.helper(root.left, sum) + self.helper(root.right, sum)
        
        
    def helper(self, root, sum):
        cnt = 0
        if root == None:
            return 0
        
        if root.val == sum:
            cnt += 1
            
        cnt += self.helper(root.left, sum-root.val)
        cnt += self.helper(root.right, sum-root.val)
        
        return cnt

n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n1.right = n2
n2.right = n3

sol = Solution()
print sol.pathSum(n1, 3)
