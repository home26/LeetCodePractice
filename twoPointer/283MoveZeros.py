class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        j = 0
        for i in range(size):
            if nums[i]:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
