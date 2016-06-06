/*
Given a binary tree, return the sum of vertical order traversal of its nodes' values in each col. (ie, from top to bottom, column by column).
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode { 
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> verticalOrderSum(TreeNode* root) {
        if (!root)
            return {};
        TreeNode* sum = new TreeNode(0);
        TreeNode* head = sum;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, sum});
        while (q.size()) {
            TreeNode *node;
            TreeNode *sum;
            tie(node, sum) = q.front();
            q.pop();
            sum->val += node->val;
            if (node->left) {
                if(!sum->left) {
                    TreeNode* tmp = new TreeNode(0);
                    tmp->right = sum;
                    sum->left = tmp;
                    head = tmp;
                }
                q.push({node->left, sum->left});
            }
            if (node->right) {
                if(!sum->right) {
                    TreeNode* tmp = new TreeNode(0);
                    tmp->left = sum;
                    sum->right = tmp;
                }
                q.push({node->right, sum->right});
            }
        }
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->right;
        }
        return res;
    }
};

int main() {
    /*
                   3
               1       5
           0      2 4     7
     -1                 6
    */
    //-1 0 1 9 11 7
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
    vector<int> res = sol.verticalOrderSum(a1);
    for (auto e : res){
        cout<<e<<" ";
    }
    cout<<endl;

    return 0;
}
