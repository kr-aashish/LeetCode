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
    void traverse(TreeNode *treeNode, vector<int> &traversal) {
        if (!treeNode) {
            return;
        }

        traverse(treeNode->left, traversal);
        traversal.push_back(treeNode->val);
        traverse(treeNode->right, traversal);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        traverse(root, traversal);
        return traversal;
    }
};