#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#include "data_structure.h"

// This is a pretty good problem
// 1. How to implement a max heap with PQ in STL
// 2. A bunch of pointer manipulation

class Solution {
public:
    // Since we have to know to which list a number belongs,
    // we'll store the value and its list ID in this customized container
    struct MergeNode{
        int val;
        int listID;
        MergeNode(int in_val, int in_listID): val(in_val), listID(in_listID){} 
    };

    // PQ in C++ STL is max heap; we'll convert it into min heap
    // by customizing the comparator
    class CompareMergeNode{
    public:
        bool operator()(MergeNode& mn1, MergeNode& mn2){
            if(mn1.val > mn2.val) return true;
            else                  return false;    
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists){
        if(lists.size()==0) return NULL;

        priority_queue<MergeNode, vector<MergeNode>, CompareMergeNode> pq;
        vector<ListNode*> listsIter = lists;

        for(int i=0; i<lists.size(); i++){
            ListNode* currNodePtr = lists[i];
            if(currNodePtr!=NULL){
                MergeNode mn( currNodePtr->val, i );
                pq.push( mn );
            }
        }

        if(pq.size()==0) return NULL;

        ListNode* head;
        ListNode* prev;
        int currMinVal = pq.top().val;
        int currID     = pq.top().listID;
        head = new ListNode(currMinVal);
        prev = head;
        pq.pop();
        listsIter[currID] = listsIter[currID]->next; // Eliminate the item we just pop from the list
        if(listsIter[currID]!=NULL){
            pq.push( MergeNode(listsIter[currID]->val, currID) ); // Supply a new item from the same list
        }

        while(!pq.empty()){
            currMinVal = pq.top().val;
            currID     = pq.top().listID;
            ListNode* currNode = new ListNode(currMinVal);
            prev->next = currNode;
            prev = currNode;
            pq.pop();
            listsIter[currID] = listsIter[currID]->next; // Eliminate the item we just pop from the list
            if(listsIter[currID]!=NULL){
                pq.push( MergeNode(listsIter[currID]->val, currID) ); // Supply a new item from the same list
            }
        }

        return head;
    }

    void printList(ListNode* head){
        ListNode* iter = head;
        while(iter!=NULL){
            cout << iter->val << ",";
            iter = iter->next;
        }
        cout << endl;
    }

    ListNode* convertVectorToList(vector<int>& v){
        if(v.size()==0) return NULL;

        ListNode* head = new ListNode(v[0]);
        ListNode* prev = head;
        for(int i=1; i<v.size(); i++){
            ListNode* currNode = new ListNode(v[i]);
            prev->next = currNode;
            prev = prev->next;
        }
        return head;
    }
};

int main(){

    Solution s1;

    vector<int> v1{1, 3, 6, 11, 12};
    ListNode* list1 = s1.convertVectorToList(v1);
    vector<int> v2{2, 4, 7, 19, 21, 28};
    ListNode* list2 = s1.convertVectorToList(v2);
    vector<int> v3{6, 9, 12, 15};
    ListNode* list3 = s1.convertVectorToList(v3);
    vector<int> v4;
    ListNode* list4 = s1.convertVectorToList(v4);
    vector<ListNode*> lists{list1, list2, list3, list4};

    ListNode* merged = s1.mergeKLists(lists);

    s1.printList(merged);


    return 0;

}