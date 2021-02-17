class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        visited = [0] * len(nums)
        res = []
        
        def dfs(path):
            if len(path) == len(nums):
                return res.append(path)
            
            for i in range(len(nums)):
                if visited[i] != 1:
                    visited[i] = 1
                    dfs(path + [nums[i]])
                    visited[i] = 0
        dfs([])
        return res
