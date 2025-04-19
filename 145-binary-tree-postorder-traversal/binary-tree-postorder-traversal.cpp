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
    void reverseSubtreeLinks(TreeNode* startNode, TreeNode* endNode) {
        if (startNode == endNode) {
            return;  // If the start and end nodes are the same, no need to
                     // reverse
        }

        TreeNode* prev = NULL;
        TreeNode* current = startNode;
        TreeNode* next = NULL;

        // Reverse the direction of the pointers in the subtree
        while (current != endNode) {
            next = current->right;
            current->right = prev;
            prev = current;
            current = next;
        }

        // Reverse the last node
        current->right = prev;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode dummy(-1);
        TreeNode* dummyNode = &dummy;
        dummyNode->left = root;

        root = dummyNode;

        TreeNode* curr = root;
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