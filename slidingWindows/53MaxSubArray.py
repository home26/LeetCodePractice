class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sumVal = 0
        outPut = float('-inf')
        for i in range(len(nums)):
            sumVal = max(sumVal + nums[i], nums[i])
            outPut = max(outPut, sumVal)
        return outPut
