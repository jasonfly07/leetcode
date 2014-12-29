import numpy as np
import math

class Solution:
    # This is called "bijective base-26 conversion" (1-26 instead of 0-25)
    # Due to the lack of 0, we deduct 1 from num everytime we shift to the next digit
    # it's a bit unintuitive.
    def convertToTitle(self, num):
        output = ""

        while num>0:
            num -= 1
            q = num%26
            r = num/26
            currChar = chr( ord('A')+q )
            output = currChar+output
            num = r

        return output

    # This is regular base-26 conversion (for comparison)
    def base26(self, num):
        allDigits = []

        while num >= 26:
            q = num/26
            r = num%26
            allDigits.append(r)
            num = q
        allDigits.append(num)

        return allDigits
            



def main():
    num = 702

    s1 = Solution()
    print s1.convertToTitle(num)

    

if __name__ == "__main__":
    main()
