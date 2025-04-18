/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isMirror(TreeNode* nodeOne, TreeNode* nodeTwo) {
        if (!nodeOne and !nodeTwo) {
            return true;
        }

        if (!nodeOne or !nodeTwo) {
            return false;
        }

        if (nodeOne->val != nodeTwo->val) {
            return false;
        }

        return isMirror(nodeOne->left, nodeTwo->right) and 
            isMirror(nodeOne->right, nodeTwo->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};