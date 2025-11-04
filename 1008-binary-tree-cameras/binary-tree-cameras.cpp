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
    int minCameraCover(TreeNode* root) {
        int result = 0;
        int rootCameraCoverage = dfs(root, result);
        int minCamera = (rootCameraCoverage < 1 ? 1 : 0) + result;
        return minCamera;
    }

    int dfs(TreeNode* node, int &result) {
        if (!node) {
            return 2;
        }

        int left = dfs(node->left, result);
        int right = dfs(node->right, result);
        if (left == 0 or right == 0) {
            result++;
            return 1;
        } else if (left == 1 or right == 1) {
            return 2;
        } else {
            return 0;
        }
    }
};