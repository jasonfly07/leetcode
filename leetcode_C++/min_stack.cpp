#include <iostream>
#include <limits>
using namespace std;






class MinStack{
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    MinStack(){
        head = NULL;
        minHead = NULL;
    }

    bool isEmpty(){
        return (head == NULL)? true: false;
    }

    void push(int x){
        ListNode* newNode = new ListNode(x);
        if(isEmpty() || (newNode->val <= minHead->val)){
            ListNode* newMin = new ListNode(newNode->val);
            newMin->next = minHead;
            minHead = newMin;
        }
        newNode->next = head;
        head = newNode;
    }

    void pop(){
        ListNode* temp = head;
        head = head->next;

        if(temp->val == minHead->val){
            ListNode* minTemp = minHead;
            minHead = minHead->next;
            delete[] minTemp;
        }
        
        delete[] temp;
    }

    int top(){
        return head->val;
    }

    int getMin(){
        return minHead->val;
    }

    void printStack(){
        ListNode* iter1 = head;

        cout << "Stack: ";
        while(iter1!=NULL){
            cout << iter1->val << ",";
            iter1 = iter1->next;
        }
        cout << endl;

        cout << "Min: ";
        ListNode* iter2 = minHead;
        while(iter2!=NULL){
            cout << iter2->val << ",";
            iter2 = iter2->next;
        }
        cout << endl;
    }

private:
    ListNode* minHead;
    ListNode* head;
};

int main(){

    MinStack ms1;
    ms1.push(2);
    ms1.push(0);
    ms1.push(3);
    ms1.push(0);
    // ms1.printStack();
    cout << ms1.getMin() << endl << endl;
    
    ms1.pop();
    // ms1.printStack();
    cout << ms1.getMin() << endl << endl;
    
    ms1.pop();
    // ms1.printStack();
    cout << ms1.getMin() << endl << endl;
    
    ms1.pop();
    cout << ms1.getMin() << endl << endl;

    return 0;
}