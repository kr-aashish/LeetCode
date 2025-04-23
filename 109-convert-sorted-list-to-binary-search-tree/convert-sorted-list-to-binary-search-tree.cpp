/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* createTree(int left, int right, ListNode* &head) {
        if (left > right) {
            return NULL;
        }

        int mid = (left + right) / 2;

        TreeNode* leftChild = createTree(left, mid - 1, head);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        
        root->left = leftChild;
        root->right = createTree(mid + 1, right, head);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        int sz = 0;
        ListNode* node = head;
        while (node) {
            sz++;
            node = node->next;
        }

        return createTree(0, sz - 1, head);
    }
};