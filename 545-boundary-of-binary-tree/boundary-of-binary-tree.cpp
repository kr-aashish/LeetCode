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
    void populateLeftBoundary(TreeNode* node, vector<int> &leftBoundary) {
        while (node->left or node->right) {
            leftBoundary.push_back(node->val);
            if (node->left) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }

    void populateRightBoundary(TreeNode* node, vector<int> &rightBoundary) {
        while (node->left or node->right) {
            rightBoundary.push_back(node->val);
            if (node->right) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }

    void populateLeafBoundary(TreeNode* node, vector<int> &leafBoundary) {
        if (!node) {
            return;
        }

        if (!node->left and !node->right) {
            leafBoundary.push_back(node->val);
            return;
        }

        populateLeafBoundary(node->left, leafBoundary);
        populateLeafBoundary(node->right, leafBoundary);
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> leftBoundary;
        if (root->left) {
            populateLeftBoundary(root->left, leftBoundary);
        }
        
        vector<int> rightBoundary;
        if (root->right) {
            populateRightBoundary(root->right, rightBoundary);
        }

        vector<int> leafBoundary;
        populateLeafBoundary(root->left, leafBoundary);
        populateLeafBoundary(root->right, leafBoundary);

        vector<int> boundary;
        boundary.push_back(root->val);
        for (auto val : leftBoundary) {
            boundary.push_back(val);
        }
        for (auto val : leafBoundary) {
            boundary.push_back(val);
        }
        reverse(rightBoundary.begin(), rightBoundary.end());
        for (auto val : rightBoundary) {
            boundary.push_back(val);
        }

        return boundary;
    }
};