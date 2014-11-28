#include "data_structure.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        ListNode* currA = headA;
        ListNode* currB = headB;
        
        while(currA != NULL){
            lengthA++;
            currA = currA->next;
        }
        while(currB != NULL){
            lengthB++;
            currB = currB->next;
        }
        // Reset the two iterators
        currA = headA;
        currB = headB;


        if(lengthA==0 || lengthB==0) return NULL;

        int commonLength = 0;

        if(lengthA > lengthB){
            for(int i=0; i<(lengthA-lengthB); i++){
                currA = currA->next;
            }
            commonLength = lengthB;
        }
        else if(lengthB > lengthA){
            for(int i=0; i<(lengthB-lengthA); i++){
                currB = currB->next;
            }
            commonLength = lengthA;
        }
        else{
            // If lengthA == lengthB, do nothing.
            commonLength = lengthA;
        }

        for(int i=0; i<commonLength; i++){
            if(currA == currB){
                return currA;
            }
            else{
                currA = currA->next;
                currB = currB->next;
            }
        }
        return NULL;
    }
};

int main(){

    return 0;
}