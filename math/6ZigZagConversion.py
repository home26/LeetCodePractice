class Solution:
    def convert(self, s: str, numRows: int) -> str:
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
            
        resultlist = []
        gap = 2 * numRows - 2
        
        for i in range(0, numRows):
            temp1 = i
            temp2 = gap - i
            
            if temp1 == 0 or temp1 == numRows-1:
                while temp1 < len(s):
                    resultlist.append(s[temp1])
                    temp1 = temp1 + gap
                    
            else:
                while temp1 < len(s):
                   resultlist.append(s[temp1])
                   temp1 = temp1 + gap
                   if temp2 < len(s):
                       resultlist.append(s[temp2])
                       temp2 = temp2 + gap
        
        resultstr = ''.join(resultlist)
        return resultstr
