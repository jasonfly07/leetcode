// This problem is essentially about finding the global minimum on
// a line chart.
// Since we can "pick" a starting point to ensure the whole chart is above
// 0 (i.e. never run out of gas), we'll simply pick the point immediately
// after the global minimum.
// If, howwever, the line chart is decaying with each cycle, then it's impossible
// to find a global minimum. 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();

        int currGas = 0;
        int minGas = 0;
        int minI = 0;
        for(int i=0; i<N; i++){
        	currGas += gas[i];
        	currGas -= cost[i];
        	if(currGas < minGas){
        		minGas = currGas;
        		minI = i;
        	}
        }
        if(currGas < 0) return -1;
        else            return (minI+1)%N;
    }
};

int main(){

	return 0;
}