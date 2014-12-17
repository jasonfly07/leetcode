// This is a pretty simple one, but it's a nice practice on operator overloading

// One interesting problem found in this one: 
// If i is out of range, vector[i] doesn't always yield 0 (it might be a garbage value)
// so always actively check if 

#include <iostream>
#include <ostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2){

        Version v1(version1);
        Version v2(version2);

        // cout << "Version1 is " << v1 << endl;
        // cout << "Version2 is " << v2 << endl;


        if(v1 > v2){
            return 1;
        }
        else if(v1 < v2){
            return -1;
        }
        else{// v1 = v2
            return 0;
        }
    }

    class Version{
    private:
        vector<int> parts;
    public:
        Version(string version){
            string delimiter = ".";
            int dotPos = -1;
            vector<int> allDotPos;
            while(true){
                dotPos = version.find(delimiter, dotPos+1);
                if(dotPos!=-1) allDotPos.push_back(dotPos);
                else           break;
            }
            allDotPos.push_back(version.size());

            // The first one is pushed seperately because of the way indices are defined
            // It's a really trivial/tricky problem that demands a more elegant solution.
            parts.push_back( stoi(version.substr(0, allDotPos[0])) );
            for(int i=0; i<allDotPos.size()-1; i++){
                // cout << i << "," << i+1 << endl;
                string currStr = version.substr(allDotPos[i]+1, allDotPos[i+1]);
                int currVal = stoi(currStr);
                parts.push_back( currVal );
            }

            // for(int i: parts) cout << i << ",";

        }

        friend ostream& operator<< (ostream &out, Version &ver);
        friend bool operator== (Version &ver1, Version &ver2);
        friend bool operator!= (Version &ver1, Version &ver2);
        friend bool operator> (Version &ver1, Version &ver2);
        friend bool operator< (Version &ver1, Version &ver2);
    };

    friend ostream& operator<< (ostream &out, Version &ver){
        for(int i: ver.parts) out << i << ",";
        return out;
    }

    friend bool operator== (Version &ver1, Version &ver2){
        int ver1size = ver1.parts.size();
        int ver2size = ver2.parts.size();
        int maxSize;
        if(ver1size > ver2size){
            maxSize = ver1size;
            for(int i=0; i<ver1size-ver2size; i++){
                ver2.parts.push_back(0);
            }    
        }
        else if(ver1size < ver2size){
            maxSize = ver2size;
            for(int i=0; i<ver2size-ver1size; i++){
                ver1.parts.push_back(0);
            }    
        }
        else maxSize = ver1size;

        for(int i=0; i<maxSize; i++){
            if(ver1.parts[i] != ver2.parts[i]) return false;
        }

        return true;
    }

    friend bool operator!= (Version &ver1, Version &ver2){
        return !(ver1 == ver2);
    }

    friend bool operator> (Version &ver1, Version &ver2){
        int ver1size = ver1.parts.size();
        int ver2size = ver2.parts.size();
        int maxSize;
        if(ver1size > ver2size){
            maxSize = ver1size;
            for(int i=0; i<ver1size-ver2size; i++){
                ver2.parts.push_back(0);
            }    
        }
        else if(ver1size < ver2size){
            maxSize = ver2size;
            for(int i=0; i<ver2size-ver1size; i++){
                ver1.parts.push_back(0);
            }    
        }
        else maxSize = ver1size;

        for(int i=0; i<maxSize; i++){
                 if(ver1.parts[i] > ver2.parts[i]) return true;
            else if(ver1.parts[i] < ver2.parts[i]) return false;
            else                                   continue;
        }

        return false;
    }

    friend bool operator< (Version &ver1, Version &ver2){
        if(ver1==ver2 || ver1>ver2) return false;
        else                        return true;
    }
};

int main(){

    Solution s1;

    cout << s1.compareVersion("19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0", "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000") << endl;

    return 0;
}