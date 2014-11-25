class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        mRow = len(matrix)
        mCol = len(matrix[0])

        rowRecord = [False for x in range(mRow)]
        colRecord = [False for x in range(mCol)]

        for i in range(0, mRow):
            for j in range(0, mCol):
                if matrix[i][j] == 0:
                    rowRecord[i] = True
                    break

        for j in range(0, mCol):
            for i in range(0, mRow):
                if matrix[i][j] == 0:
                    colRecord[j] = True
                    break

        # print matrix

        for i in range(0, mRow):
            if rowRecord[i] == True:
                for j in range(0, mCol):
                    matrix[i][j] = 0

        for j in range(0, mCol):
            if colRecord[j] == True:
                for i in range(0, mRow):
                    matrix[i][j] = 0





def main():
    matrix = [[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]
    # matrix = [[1,1,1],[0,1,2]]

    s1 = Solution()
    s1.setZeroes(matrix)

    print matrix


if __name__ == "__main__":
    main()