#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num){
        int n = num.size();
        if(num[0] < num[n-1]) return num[0];
        else                  return findMin_help(num, 0, n-1); 
    }

    int findMin_help(vector<int> &num, int i, int j){
        cout << "start: " << i << "," << j << endl;
        if(i==j) return num[i];

        int mid = (i+j)/2;
        cout << "mid: " << mid << endl;
        if(mid!=0 && num[mid-1] > num[mid]){
            return num[mid];
        }
        else if(num[mid] > num[mid+1]){
            return num[mid+1];
        }
        else{
            if(num[mid]<=num[i] && num[mid]<=num[j]){
                cout << "go left" << endl;
                return findMin_help(num, i, mid-1);
            }
            if(num[mid]>=num[i] && num[mid]>=num[j]){
                cout << "go right" << endl;
                return findMin_help(num, mid+1, j);
            }
        }
    }
};

int main(){
    vector<int> v{2,1};

    Solution s1;
    cout << s1.findMin(v) << endl;


    return 0;
}

// If mid < left and right: left
// If mid > left and right: right
// 9 10 11 1 2 [3] 4 5 6 7 8
// 9 10 [11] 1 2
// 1 2




// 4 5 6 7 8 [9] 10 11 1 2 3 