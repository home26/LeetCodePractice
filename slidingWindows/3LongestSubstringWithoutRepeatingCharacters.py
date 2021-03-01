class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dict = {}
        longest = 0
        start = 0
        for i, c in enumerate(s):
            if c in dict and dict[c] >= start:
                start = dict[c] + 1
            else:
                longest = max(longest, i-start+1)
            dict[c] = i
        return longest
