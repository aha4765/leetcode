class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.orig = list(nums)
        self.nums = nums
        

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        nums = list(self.orig)
        return nums
        

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        array = list(self.orig)
        for i in range(len(array)):
            swap = random.randint(i, len(array)-1)
            temp = array[i]
            array[i] = array[swap]
            array[swap] = temp
            
        return array
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
