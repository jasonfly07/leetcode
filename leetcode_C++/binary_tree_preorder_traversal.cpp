#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root){
        stack<TreeNode*> mainStack;
        stack<bool> flagStack;
        vector<int> output;
        if(root==NULL) return output;
        
        mainStack.push(root);
        flagStack.push(false);

        while(!mainStack.empty()){
            TreeNode* currNode = mainStack.top();
            int       currFlag = flagStack.top();
            mainStack.pop();
            flagStack.pop();
            if(currFlag==true){
                output.push_back(currNode->val);
            }
            else{
                if(currNode->right != NULL){
                    mainStack.push(currNode->right);
                    flagStack.push(false);
                }
                if(currNode->left != NULL){
                    mainStack.push(currNode->left);
                    flagStack.push(false);
                }
                mainStack.push(currNode);
                flagStack.push(true);
            }
        }

        return output;
    }
};

int main(){
    TreeNode tn1(1);
    TreeNode tn2(2);
    TreeNode tn3(3); 
    TreeNode tn4(4);
    TreeNode tn5(5);
    TreeNode tn6(6);
    TreeNode tn7(7);
    (&tn1)->left = &tn2;
    (&tn1)->right = &tn3;
    // (&tn2)->left = &tn4;
    // (&tn2)->right = &tn5;
    (&tn3)->left = &tn6;
    (&tn3)->right = &tn7;

    Solution s1;

    for(auto v : s1.preorderTraversal(&tn1)){
        cout << v << ",";
    }

    return 0;
}