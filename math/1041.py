class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        
        x, y = 0, 0
        dirctionStatus = 0
        
        for i in instructions:
            if i == 'G':
                if dirctionStatus == 0:
                    y += 1
                elif dirctionStatus == 1:
                    x -= 1
                elif dirctionStatus == 2:
                    y -= 1
                elif dirctionStatus == 3:
                    x += 1
            if i == 'L':
                dirctionStatus = (dirctionStatus + 1) % 4
            if i == 'R':
                dirctionStatus = (dirctionStatus - 1) % 4
        if (x == 0 and y == 0) or dirctionStatus != 0:
            return True
        else:
            return False
