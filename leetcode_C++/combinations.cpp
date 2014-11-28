#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> allComb;
public:
    vector<vector<int>> combine(int n, int k){
        vector<int> empty;
        combine_help(1, n, k, empty);
        return allComb;
    }

    void combine_help(int start, int end, int k, vector<int> prevComb){
    	for(int i=start; i<=(end-k+1); i++){
    		vector<int> currComb = prevComb;
    		currComb.push_back(i);

    		if(k==1){
    			allComb.push_back(currComb);
    		}
    		else{
    			combine_help(i+1, end, k-1, currComb);
    		}
    	}
    }
};

int main(){
	vector<int> v1;
	vector<int> v2;

	v1.push_back(3);
	v1.push_back(5);

	v2 = v1;

	v1.push_back(7);

	cout << v2[2] << endl;

	return 0;
}