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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head or !head->next)
            return head;

        ListNode *kthNode = head, *currNode = head;
        int count = k, len = 0;
        while (count or currNode) {
            if (count) {
                kthNode = currNode;
                count--;
            }
            len++;
            currNode = currNode->next;
        }

        ListNode *kthNodeFromEnd = head;
        count = len - k;
        while (count) {
            kthNodeFromEnd = kthNodeFromEnd->next;
            count--;
        }
        swap(kthNode->val, kthNodeFromEnd->val);

        return head;
    }
};