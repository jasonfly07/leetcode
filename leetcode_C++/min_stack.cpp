#include <iostream>
#include <stack>
using namespace std;

class MinStack{
public:
    MinStack(){
    }

    void push(int x){
        if(mainStack.empty() || x<=minStack.top()){
            minStack.push(x);
        }
        mainStack.push(x);
    }

    void pop(){
        if(mainStack.top()==minStack.top()){
            minStack.pop();
        }
        mainStack.pop();
    }

    int top(){
        return mainStack.top();
    }

    int getMin(){
        return minStack.top();
    }

private:
    stack<int> mainStack;
    stack<int> minStack;
};

int main(){

    MinStack ms1;
    ms1.push(0);
    ms1.push(1);
    ms1.push(0);
    // ms1.printStack();
    cout << ms1.getMin() << endl << endl;
    // cout << ms1.top() << endl << endl;
    ms1.pop();
    cout << ms1.getMin() << endl << endl;

    return 0;
}