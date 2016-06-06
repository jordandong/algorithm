/*
Convert a BST to a sorted circular doubly-linked list in-place.
Think of the left and right pointers as synonymous to the previous and next pointers in a doubly-linked list.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
using namespace std;

struct TreeNode { 
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void treeToDoublyList(TreeNode *p, TreeNode* &prev, TreeNode* &head) {
        if (!p)
             return;
        treeToDoublyList(p->left, prev, head);
        p->left = prev;
        if (prev)
            prev->right = p;
        else
            head = p;
        TreeNode *right = p->right;
        head->left = p;
        p->right = head;
        prev = p;
        treeToDoublyList(right, prev, head);
    }
 
    TreeNode* treeToDoublyList(TreeNode *root) {
        TreeNode *prev = NULL;
        TreeNode *head = NULL;
        treeToDoublyList(root, prev, head);
        return head;
    }

/*
    TreeNode* flatBST(TreeNode* root) {
        if (!root)
            return NULL;
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* pre = dummy;
        flatBSTHelper(root, pre);
        dummy->right->left = pre;
        pre->right = dummy->right;
        root = dummy->right;
        delete dummy;
        return root;
    }

    void flatBSTHelper(TreeNode* root, TreeNode* &pre) {
        if (!root)
            return;
        flatBSTHelper(root->left, pre);
        pre->right = root;
        root->left = pre;
        pre = pre->right;
        flatBSTHelper(root->right, pre);
    }
*/
};

int main() {
    TreeNode* a1 = new TreeNode(3);
    a1->left =new TreeNode(1);
    a1->left->right =new TreeNode(2);
    a1->right =new TreeNode(5);
    a1->right->left =new TreeNode(4);
    a1->right->right =new TreeNode(7);
    a1->right->right->left =new TreeNode(6);
    a1->left->left =new TreeNode(0);
    a1->left->left->left =new TreeNode(-1);
    Solution sol;  
    //a1 = sol.flatBST(a1);
    a1 = sol.treeToDoublyList(a1);
    TreeNode* cur = a1;
    int cnt = 18;
    while(cur && cnt) {
        cout<<cur->val<<" ";
        cur = cur->right;\
        cnt--;
    }
    cout<<endl;
    cnt = 18;
    cur = a1->left;
    while(cur && cnt) {
        cout<<cur->val<<" ";
        cur = cur->left;
        cnt--;
    }
    cout<<endl;
    return 0;
}
