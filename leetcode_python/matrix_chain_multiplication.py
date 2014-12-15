import numpy as np
import math
import sys

class Solution:
    dp = []
    def minChainOrder(self, matrices):
        # N is the number of matrices
        N = len(matrices)-1
        self.dp = [ [-1 for j in range(0, N)] for i in range(0, N)]

        self.minChainOrder_help(matrices, 0, N-1)

        print 'The final cost matrix: ',self.dp

        return self.dp[0][N-1]

    def minChainOrder_help(self, matrices, i, j):
        # First, if (i,j) is already in dp, use it
        if self.dp[i][j] != -1:
            return self.dp[i][j]

        if i==j:
            self.dp[i][j] = 0
            return 0

        if i+1==j:
            self.dp[i][j] = matrices[i]*matrices[j]*matrices[j+1]
            return self.dp[i][j]

        # If j-i>1
        alltimeMin = sys.maxsize
        for k in range(i, j):
            # print i,',',k,' ',k+1,',',j
            if self.dp[i][k]!=-1:
                leftMin = self.dp[i][k]
            else:
                leftMin = self.minChainOrder_help(matrices, i, k)

            if self.dp[k+1][j]!=-1:
                rightMin = self.dp[k+1][j]
            else:
                rightMin = self.minChainOrder_help(matrices, k+1, j)

            # This line caused a lot of bugs
            currMin = leftMin + rightMin + matrices[i]*matrices[k+1]*matrices[j+1]

            if currMin<alltimeMin:
                alltimeMin = currMin

        self.dp[i][j] = alltimeMin
        return alltimeMin

        


def main():
    s1 = Solution()
    matrices = [10, 20, 30, 40, 30]

    print s1.minChainOrder(matrices)



if __name__ == "__main__":
    main()