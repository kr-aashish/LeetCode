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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        nodes.push(root);

        while (nodes.size() >= 2) {
            TreeNode* nodeOne = nodes.front();
            nodes.pop();
            TreeNode* nodeTwo = nodes.front();
            nodes.pop();

            if (!nodeOne and !nodeTwo) {
                continue;
            } else if (!nodeOne or !nodeTwo) {
                return false;
            } else if (nodeOne->val != nodeTwo->val) {
                return false;
            }

            nodes.push(nodeOne->left);
            nodes.push(nodeTwo->right);
            nodes.push(nodeOne->right);
            nodes.push(nodeTwo->left);
        }

        return true;
    }
};