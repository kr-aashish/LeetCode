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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Missed null root with 0 targetSum is not valid!
        if (root == NULL) {
            return false;
        }

        // Missed it, the value should really be leaf!
        if (root->val == targetSum and !root->left and !root->right) {
            return true;
        }

        int value = root->val;
        return hasPathSum(root->left, targetSum - value) or 
            hasPathSum(root->right, targetSum - value);
    }
};