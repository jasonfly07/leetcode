// 1. How to generate random numbers

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> slidingMax(const vector<int>& v, int k){
    

}




int main(){

    srand(time(NULL));

    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(rand()%50);
    }
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ",";
    }
    cout << endl;

    return 0;

}