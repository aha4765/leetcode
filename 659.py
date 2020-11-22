class Solution(object):
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 6:
            return False 
        
        for i in range(len(nums)-2):
            if (nums[i] == nums[i+1] -1) and (nums[i+1] == nums[i+2]-1):
                nums.pop(i)
                nums.pop(i)
                nums.pop(i)
                
        for i in range(len(nums)-2):
            if nums[i] == nums[i+1] -1 and nums[i+1] == nums[i+2]-1:
                return True
            
        return False

sol = Solution()
sol.isPossible([1,2,3,3,4,5])
