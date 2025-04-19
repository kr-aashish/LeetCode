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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;

        vector<int> traversal;
        TreeNode* curr = root;
        while (curr!= NULL or !nodes.empty()) {
            while (curr != NULL) {
                nodes.push(curr);
                curr = curr->left;
            }

            curr = nodes.top();
            nodes.pop();
            traversal.push_back(curr->val);
            curr = curr->right;
        }

        return traversal;
    }
};