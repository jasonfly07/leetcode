import numpy as np
import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Solution:
    def isInsideTriangle(self, triangle, p):
        angleSum = 0
        epsilon = 0.001
        for i in range(0,3):
            tri1 = triangle[i % 3]
            tri2 = triangle[(i+1) % 3]
            
            vec1 = [tri1.x-p.x, tri1.y-p.y]
            vec2 = [tri2.x-p.x, tri2.y-p.y]

            currAngle = math.acos( np.dot(vec1, vec2)/(np.linalg.norm(vec1)*np.linalg.norm(vec2)) ) * 180/3.1415926
            angleSum += currAngle

        print 'The sum of angles:',angleSum

        if math.fabs(angleSum-360)<epsilon:
            return True
        else:
            return False


def main():
    triangle = [Point(0,0), Point(1,2), Point(5,-2)]

    s1 = Solution()

    print s1.isInsideTriangle(triangle, Point(2,0))
    

if __name__ == "__main__":
    main()