// For the test case where n=2147483647,
// currMultiplier has to be double to avoid overflow


// There're 2 approaches, the second one is divide & conquer, which is simpler and faster.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double pow(double x, int n){
        // First, handle some trivial cases
        if(x==0)  return 0;
        if(x==1)  return 1;
        if(x==-1) return (n%2)==0? 1: -1;
        if(n==1)  return x;
        
        // If n<0, transfer the negative sign to x
        if(n<0){
            x = 1/x;
            n *= -1;
        }

        vector<double> allFactors;
        double currMultiplier = 1;
        while(n>0){
            // cout << "n: " << n << endl;
            // cout << "multi:" << currMultiplier << endl;
            if(n == currMultiplier){
                allFactors.push_back(currMultiplier);

                n -= currMultiplier;
                currMultiplier = 1;
            }
            else if(n > currMultiplier){
                currMultiplier *= 2;
            }
            else{ // n < currMultiplier
                currMultiplier /= 2;
                allFactors.push_back(currMultiplier);
                n -= currMultiplier;
                currMultiplier = 1;
            }   
        }

        double output = 1;

        for(int i=0; i<allFactors.size(); i++){
            cout << allFactors[i] << endl;
            double goalPower = allFactors[i];
            double currPower = 1;
            double currBase = x;
            while(currPower!=goalPower){
                currBase *= currBase;
                currPower *= 2;
            }
            output *= currBase;
        }

        return output;
    }

    double pow2(double x, int n){
        return (n<0)? 1/pow_recur(x, n): pow_recur(x, n); 
    }

    double pow_recur(double x, int n){
        if(n==1) return x;
        if(n==-1) return x;
        else{
            if(n%2==0){
                double temp = pow_recur(x, n/2);
                return temp*temp;
            }
            else{
                return pow_recur(x, (n-1)/2) * pow_recur(x, ((n-1)/2)+1);
            }
        }
    }
};

int main(){
    Solution s1;
    cout << s1.pow2(2, -3) << endl;

    return 0;

}