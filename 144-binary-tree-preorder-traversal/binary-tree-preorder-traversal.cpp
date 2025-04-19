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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        nodes.push(root);
        vector<int> traversal;

        while (!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();

            if (node != NULL) {
                traversal.push_back(node->val);

                if (node->right != NULL) {
                    nodes.push(node->right);
                }
                // Left will be pushed later, to process it first
                if (node->left != NULL) {
                    nodes.push(node->left);
                } 
            }
        }

        return traversal;
    }
};