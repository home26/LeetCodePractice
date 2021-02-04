class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        res = 1
        for i in range(2, int(sqrt(2*N)) + 1):
            if (N - (i-1)*i/2) % i == 0:
                res += 1
        return res
