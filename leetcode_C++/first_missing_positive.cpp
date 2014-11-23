#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n){
        int iterL = 0;
        int iterR = n-1;


        while(iterL < iterR){
            while(A[iterL] >  0 && iterL < n-1) iterL++;
            while(A[iterR] <= 0 && iterR > 0  ) iterR--;
            if(iterL >= iterR) break;
            else{
                int temp = A[iterL];
                A[iterL] = A[iterR];
                A[iterR] = temp;
            }
        }

        int lastPosInd = -1;
        for(int i=0; i<=n-1; i++){
            if(A[i]<=0) break;
            else        lastPosInd++;
        }

        cout << "After separation: "; printArray(A, n);
        // If lastPosInd is -1, it means the entire array is non-positive
        cout << "Index of the last positive element: " << lastPosInd << endl;
        if(lastPosInd<0) return 1;

        for(int i=0; i<=lastPosInd; i++){
            if(abs(A[i])-1<=lastPosInd && (A[(int)(abs(A[i])-1)]>0)){
                A[(int)(abs(A[i])-1)] *= -1;
            } 
        }
        cout << "After searching: ";
        printArray(A, n);

        int output = 1;
        for(int i=0; i<=lastPosInd; i++){
            if(A[i]>0) break;
            else       output++;
        }
       
        return output;
    }

    void printArray(int a[], int n){
        for(int i=0; i<n; i++){
            cout << a[i] << ",";
        }
        cout << endl;
    }
};

int main(){

    const int size = 1;
    int A[size] = {2};
    // int A[size] = {1,2,-3,4,-5,6,-7};
    // int A[size] = {1,2,4};
    Solution s1;
    cout << "The original array: ";
    s1.printArray(A, size);
    int answer = s1.firstMissingPositive(A, size);
    cout << "The first missing positive is: " << answer << endl;;

    return 0;

}