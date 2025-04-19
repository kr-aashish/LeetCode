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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;

        TreeNode* prev = NULL;
        stack<TreeNode*> nodes;
        TreeNode* curr = root;

        while (curr != NULL or !nodes.empty()) {
            if (curr != NULL) {
                nodes.push(curr);
                curr = curr->left;
            } else {
                curr = nodes.top();

                if (curr->right == NULL or curr->right == prev) {
                    traversal.push_back(curr->val);
                    nodes.pop();
                    prev = curr;
                    curr = NULL;
                } else {
                    curr = curr->right;
                }
            }
        }

        return traversal;
    }
};