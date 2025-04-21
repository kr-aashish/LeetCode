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
    void calculateSubtreeSize(TreeNode* node, unordered_map<TreeNode*, int> &size) {
        if (node == NULL) {
            size[node] = 0;
            return;
        }

        calculateSubtreeSize(node->left, size);
        calculateSubtreeSize(node->right, size);
        size[node] = size[node->left] + size[node->right] + 1;
    }

    void calculateKthSmallest(TreeNode* node, unordered_map<TreeNode*, int> &size, int &kthSmallest, int k) {
        if (node == NULL) {
            return;
        }

        if (k <= size[node->left]) {
            calculateKthSmallest(node->left, size, kthSmallest, k);
        } else if (k == size[node->left] + 1) {
            kthSmallest = node->val;
        } else {
            calculateKthSmallest(node->right, size, kthSmallest, k - size[node->left] - 1);
        }
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, int> size;
        calculateSubtreeSize(root, size);

        int kthSmallest = -1;
        calculateKthSmallest(root, size, kthSmallest, k);
        return kthSmallest;
    }
};