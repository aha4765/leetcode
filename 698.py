class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        sum = 0
        for num in nums:
            sum += num
        if sum%k != 0:
            return False
        sum /= k
        groups = [0]*k
        return self.help(nums, sum, groups, 0)
        
    def help(self, nums, sum, groups, pos):
        if pos == len(nums):
            for num in groups:
                if num != sum:
                    return False
            return True
        
        for i in range(len(groups)):
            if groups[i] + nums[pos] <= sum:
                groups[i] += nums[pos]
                if self.help(nums, sum, groups, pos+1) is True:
                    return True
                groups[i] -= nums[pos]
                
        return False

sol = Solution()
print sol.canPartitionKSubsets([3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269], 5)
