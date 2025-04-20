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
    void reverseSubtreeLinks(TreeNode* start, TreeNode* end) {
        if (start == end) {
            return;
        }
        
        TreeNode* curr = start;
        TreeNode* prev = NULL;
        TreeNode* next = NULL;
        while (curr != end) {
            next = curr->right;
            curr->right = prev;

            prev = curr;
            curr = next;
        }

        curr->right = prev;
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        dummy->left = root;

        TreeNode* curr = dummy;
        TreeNode* prev = NULL;
        vector<int> traversal;

        while (curr != NULL) {
            if (curr->left == NULL) {
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
                    TreeNode* node = prev;
                    reverseSubtreeLinks(curr->left, prev);
                    while (node != curr->left) {
                        traversal.push_back(node->val);
                        node = node->right;
                    }
                    traversal.push_back(node->val);
                    reverseSubtreeLinks(prev, curr->left);

                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return traversal;
    }
};