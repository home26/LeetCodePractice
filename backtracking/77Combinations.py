class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        def dfs(start, count, path):
            if count == k:
                res.append(path)
            for i in range(start+1, n+1):
                count += 1
                dfs(i, count, path + [i])
                count -= 1
        dfs(0, 0, [])
        return res
