// Problem: Please implement a function which gets the intersection of two sorted arrays. 
// Assuming numbers in each array are unique.
// For example, if the two sorted arrays as input are {1, 4, 7, 10, 13} and {1, 3, 5, 7, 9}, 
// it returns an intersection array with numbers {1, 7}.

#include <iostream>
#include <vector>
using namespace std;

void getIntersections(const vector<int>& v1, const vector<int>& v2, vector<int>& intersect){
    vector<int>::const_iterator iter1 = v1.begin();
    vector<int>::const_iterator iter2 = v2.begin();

    intersect.clear();

    while(iter1!=v1.end() && iter2!=v2.end()){
        if(*iter1 == *iter2){
            intersect.push_back(*iter1);
            iter1++;
        }
        else if(*iter1 > *iter2){
            iter2++;
        }
        else{// *iter1 < *iter2
            iter1++;
        }
    }
}

int main(){
    vector<int> v1{10, 20, 30, 40, 50, 60};
    vector<int> v2{5, 25, 30, 45, 55, 60};

    vector<int> intersect;

    getIntersections(v1, v2, intersect);

    cout << "The 1st array is: ";
    for(auto i: v1){
        cout << i << ",";
    }
    cout << endl;

    cout << "The 2nd array is: ";
    for(auto i: v2){
        cout << i << ",";
    }
    cout << endl;

    cout << "The intersection is: ";
    for(auto i: intersect){
        cout << i << ",";
    }
    cout << endl;

    return 0;
}