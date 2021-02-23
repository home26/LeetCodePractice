class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dict = {}
        for i in range(len(strs)):
            temp = "".join(sorted(strs[i]))
            if temp in dict:
                dict[temp].append(strs[i])
            else:
                dict[temp] = [strs[i]]
        return [value for key, value in dict.items()]
