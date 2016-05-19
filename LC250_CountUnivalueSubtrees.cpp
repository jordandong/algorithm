/*
Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        isUnivalSubtrees(root, &count);
        return count;
    }
    
    bool isUnivalSubtrees(TreeNode* root, int *count) {
        if (!root) {
            return true;
        }
        bool left = isUnivalSubtrees(root->left, count);
        bool right = isUnivalSubtrees(root->right, count);
        if (isSame(root, root->left, left) && isSame(root, root->right, right)) {
            ++(*count);
            return true;
        }
        return false;
    }
    
    bool isSame(TreeNode* root, TreeNode* child, bool is_uni) {
        return !child || (is_uni && root->val == child->val);
    }
};
