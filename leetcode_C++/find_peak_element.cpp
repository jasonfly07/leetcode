// Problem: Turning number is the maximum number in an array which increases 
// and then decreases. This kind of array is also named unimodal array. 
// Please write a function which gets the index of the turning number in such an array.

// For example, the turning number in array {1, 2, 3, 4, 5, 10, 9, 8, 7, 6} is 10, 
// so its index 5 is the expected output.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();

        // Initialize peak index
        int peakIndex = -1;

        int start = 0;
        int end = n-1;

        while(true){
            int mid = (start+end)/2;

            if(mid==0 && num[mid]>num[mid+1]){
                peakIndex = mid; break;
            }
            else if(mid==n-1 && num[mid]>num[mid-1]){
                peakIndex = mid; break;
            }
            else if(num[mid]>num[mid-1] && num[mid]>num[mid+1]){
                peakIndex = mid; break;
            }
            else{
                if(num[mid]<num[mid+1]){
                    start = mid+1; 
                }
                else{
                    end = mid-1;
                }
            }
        }

        return peakIndex;
    }
};

int main(){
    vector<int> v{-2147483648};
    Solution s1;

    cout << s1.findPeakElement(v) << endl;

    return 0;
}