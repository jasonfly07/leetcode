// 1. How to generate random numbers

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n){
        int dp[n];
        dp[0] = A[0];

        int alltimeMax = dp[0];

        for(int i=1; i<n; i++){
            if(dp[i-1] >= 0) dp[i] = dp[i-1] + A[i];
            else             dp[i] = A[i];

            if(dp[i]>alltimeMax) alltimeMax = dp[i];
        }

        return alltimeMax;
    }

    // This one will display the start and end
    int maxSubArray2(int A[], int n){
        int dp[n];
        dp[0] = A[0];

        int alltimeMax = dp[0];

        int start = 0;
        int end = 0;
        int maxStart = 0;
        int maxEnd = 0;

        for(int i=1; i<n; i++){
            if(dp[i-1] >= 0){
                dp[i] = dp[i-1] + A[i];
                end = i;
            }
            else{
                dp[i] = A[i];
                start = i;
                end = i;
            }

            if(dp[i]>alltimeMax){
                alltimeMax = dp[i];
                maxStart = start;
                maxEnd = end;
            }
        }

        cout << "The maximum array ranges from " << maxStart << " to " << maxEnd << endl
;        return alltimeMax;
    }
};




int main(){
    const int k = 9;
    int a[k] = {-2,1,-3,4,-1,2,1,-5,4};

    Solution s1;

    cout << s1.maxSubArray2(a, k) << endl;
 
    return 0;

}