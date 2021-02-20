class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        self.res = []
        self.count = 0
        
        def dfs(start, path, k):
            if self.count == k:
                self.res.append(path)
            for i in range(start, len(nums)):
                self.count += 1
                dfs(i+1, path+[nums[i]], k)
                self.count -= 1
        
        for k in range(len(nums)+1):
            dfs(0, [], k)
        
        return self.res
