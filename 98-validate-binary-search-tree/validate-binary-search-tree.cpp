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
    bool isValid(TreeNode* node, long long leftVal, long long rightVal) {
        if (node == NULL) {
            return true;
        }

        if (node->val <= leftVal or node->val >= rightVal) {
            return false;
        }

        bool isLeftBSTValid = isValid(node->left, leftVal, node->val);
        bool isRightBSTValid = isValid(node->right, node->val, rightVal);

        return isLeftBSTValid and isRightBSTValid;
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};