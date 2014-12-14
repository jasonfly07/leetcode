#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Sort{
public:
    void selectionSort(vector<int>& v){
        int n = v.size();

        printVector(v);

        for(int i=0; i<n; i++){
            int minInd = i;
            for(int j=i; j<n; j++){
                if(v[j] < v[minInd]) minInd = j;
            }
            swap(v[i], v[minInd]);
            printVector(v);
        }
    }

    void quickSort(vector<int>& v){
        printVector(v);
        quickSort_help(v, 0, v.size()-1);
    }

    void quickSort_help(vector<int>& v, int i, int j){
        if(i>=j) return;

        // Pick the first element as pivot
        int pivot = v[i];
        int iterL = i+1;
        int iterR = j;

        while(iterL <= iterR){
            while(v[iterL] <= pivot) iterL++;
            while(v[iterR] >  pivot) iterR--;
            if(iterL > iterR) break;
            swap(v[iterL], v[iterR]);
            printVector(v);
            iterL++; iterR--; 
        }
        swap(v[i], v[iterR]);
        printVector(v);
        quickSort_help(v, i, iterR-1);
        quickSort_help(v, iterR+1, j);
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

    Sort sort;

    vector<int> v;

    srand(time(NULL));
    
    for(int i=0; i<10; i++){
        v.push_back(rand()%100);
    }

    sort.quickSort(v);
    
    return 0;

}