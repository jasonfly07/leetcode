import math

class Solution:
    # @param num, a list of integer
    # @return an integer
    def maximumGap(self, num):
        n = len(num)
        numMin = num[0]
        numMax = num[0]
        for i in range(0, n):
            if num[i] > numMax:
                numMax = num[i]
            if num[i] < numMin:
                numMin = num[i]
        # print 'max',numMax
        # print 'min',numMin

        gap = int( math.ceil((numMax - numMin)/float(n-1)) )

        buckets    = [[] for i in range(0, n)]
        bucketsMin = [ 0 for i in range(0, n)]
        bucketsMax = [ 0 for i in range(0, n)]

        for i in range(0, n):
            # print num[i], ',', numMin, ',', gap
            k = int( math.floor( (num[i]-numMin)/float(gap) ) )
            
            if len(buckets[k])==0:
                bucketsMax[k] = num[i]
                bucketsMin[k] = num[i]
            else:
                if num[i] > bucketsMax[k]:
                    bucketsMax[k] = num[i]
                if num[i] < bucketsMin[k]:
                    bucketsMin[k] = num[i]

            buckets[k].append( num[i] )         

        # for i in range(0, n):
        #     print buckets[i]

        # print

        # for i in range(0, n):
        #     print bucketsMax[i]

        # print 

        # for i in range(0, n):
        #     print bucketsMin[i]

        # print

        maxGap = gap

        for i in range(0, n-1):
            # print i
            if len(buckets[i])!=0:
                nextInd = i+1
                while nextInd<n-1 and len(buckets[nextInd])==0:
                    nextInd += 1
                    
                # print 'nextInd:',nextInd
                if len(buckets[nextInd])==0:
                    continue
                else:
                    currGap = bucketsMin[nextInd] - bucketsMax[i]
                    if currGap > maxGap:
                        maxGap = currGap

        return maxGap
        





def main():
    num = [45, 1, 40, 7, 8, 37, 35, 13, 21, 14]

    s1 = Solution()
    print s1.maximumGap(num)

if __name__ == "__main__":
    main()