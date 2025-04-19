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
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        vector<int> traversal;

        while (curr != NULL) {
            if (curr->left == NULL) {
                traversal.push_back(curr->val);
                curr = curr->right;
            } else {
                prev = curr->left;

                while (prev->right != NULL and prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    traversal.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return traversal;
    }
};