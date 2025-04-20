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
    void processDiff(int &prevVal, int &currVal, int &minDiff) {
        minDiff = min(minDiff, currVal - prevVal);
        prevVal = currVal;
    }

public:
    int minDiffInBST(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = NULL;

        int prevVal = -1e9;
        int minDiff = INT_MAX;

        while (curr != NULL) {
            if (curr->left == NULL) {
                processDiff(prevVal, curr->val, minDiff);
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
                    processDiff(prevVal, curr->val, minDiff);
                    curr = curr->right;
                }
            }
        }

        return minDiff;
    }
};