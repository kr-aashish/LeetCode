/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node* root = node;
        while (root->parent != NULL) {
            root = root->parent;
        }

        Node* successor = NULL;
        Node* curr = root;
        while (curr) {
            if (curr->val > node->val) {
                successor = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return successor;
    }
};