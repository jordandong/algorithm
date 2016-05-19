/*
Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
   1
  / \
 2   3
/ \
4 5

return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
    3 1
*/

#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int v){
        left = NULL;
        right = NULL;
        val = v;
    }
};

class Solution{
public:
    TreeNode* UpsideDownBinaryTree(TreeNode *root){
        TreeNode *c = root, *p = NULL, *pR = NULL;
        while(c){
            TreeNode* l = c->left;
            c->left = pR;
            pR = c->right;
            c->right = p;
            p = c;
            c = l;
        }
        return p;
    }
};

int main(){
    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->left->left = new TreeNode(4);
    r->left->right = new TreeNode(5);
    Solution s;
    TreeNode* res = s.UpsideDownBinaryTree(r);
    queue<TreeNode*> q[2];
    int c = 0;
    q[c].push(res);

    while(q[c].size()){
        TreeNode* t = q[c].front();
        q[c].pop();
        if(!t)
            cout<<"# ";
        else{
            q[c^1].push(t->left);
            q[c^1].push(t->right);
            cout<<t->val<<" ";  
        }
        if(q[c].empty()){
            c ^= 1;
            cout<<endl; 
        }
    }
    return 1;
}
