// How to copy a vector?
// How to insert elements into a vector?

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &num){
        if(num.size()==1){
            vector<vector<int>> output(1, vector<int>(1,num[0]));
            return output;
        }
        else{
            vector<int> numCopy = num;
            int lastVal = numCopy.back();
            numCopy.pop_back();
            vector<vector<int>> prevOutput = permute(numCopy);
            vector<vector<int>> output;

            for(int i=0; i<prevOutput.size(); i++){
                for(int j=0; j<=prevOutput[i].size(); j++){
                    vector<int> currPerm = prevOutput[i];
                    currPerm.insert(currPerm.begin()+j, lastVal);
                    output.push_back(currPerm);
                }
            }

            return output; 
        }
        
    }
};

int main(){
    vector<int> v1{3,4,5};
    Solution s1;

    vector<vector<int>> allPerm = s1.permute(v1);

    for(vector<int> v: allPerm){
        for(int i: v){
            cout << i << ",";
        }
        cout << endl;
    }

    return 0;
}