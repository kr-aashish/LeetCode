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
    TreeNode* createTree(int leftIn, int rightIn, int leftPre, int rightPre,
    unordered_map<int, int> &inorderMap, vector<int>& inorder, vector<int>& preorder) {
        if (leftIn > rightIn) {
            return NULL;
        }

        int rootVal = preorder[leftPre];
        int breakPoint = inorderMap[rootVal];

        TreeNode* root = new TreeNode(rootVal);
        root->left = createTree(leftIn, breakPoint - 1, leftPre + 1, leftPre + (breakPoint - leftIn), inorderMap, inorder, preorder);
        root->right = createTree(breakPoint + 1, rightIn, leftPre + (breakPoint - leftIn) + 1, rightPre, inorderMap, inorder, preorder);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int sz = inorder.size();
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < sz; i++) {
            inorderMap[inorder[i]] = i;
        }

        return createTree(0, sz - 1, 0, sz - 1, inorderMap, inorder, preorder);
    }
};