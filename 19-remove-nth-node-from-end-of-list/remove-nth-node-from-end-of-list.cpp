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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* second = head;
        int counter = 1;
        while (counter <= n) {
            second = second->next;
            counter++;
        }

        if (!second) {
            return head->next;
        }

        ListNode* first = head;
        while (second->next) {
            second = second->next;
            first = first->next;
        }
        first->next = first->next->next;
        return head;
    }
};