#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Solution{
public:
    // Pick the kth smallest number 
    int quickSelect(vector<int>& v, int k){
        int i = 0;
        int j = v.size()-1;

        int output = 0;

        while(true){
            int iterL = i;
            int iterR = j;

            int pivot = v[i];

            while(iterL <= iterR){
                while(v[iterL] <= pivot) iterL++;
                while(v[iterR] >  pivot) iterR--;
                if(iterL > iterR) break;
                swap(v[iterL], v[iterR]);
                printVector(v);
                iterL++; iterR--; 
            }
            swap(v[i], v[iterR]);
        
            if(iterR==k){
                output = v[iterR];
                break;
            }
            else if(iterR > k){
                j = iterR-1;
            }
            else{// iterR < k
                i = iterR+1;
            }
        }

        return output;
    }

    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void printVector(vector<int>& v){
        for(int i: v){
            cout << i << ",";
        }
        cout << endl;
    }
};



int main(){

    Solution s1;

    vector<int> v;

    srand(time(NULL));
    
    for(int i=0; i<10; i++){
        v.push_back(rand()%100);
    }
    s1.printVector(v);

    cout << s1.quickSelect(v, 0) << endl;
    return 0;
}
