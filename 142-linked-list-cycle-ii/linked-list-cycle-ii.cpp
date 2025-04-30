/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head or !head->next) {
            return NULL;
        }

        ListNode* pSlow = head;
        ListNode* pFast = head;

        while (pFast and pFast->next) { // both
            pSlow = pSlow->next;
            pFast = pFast->next->next;

            if (pSlow == pFast) {
                break;
            }
        }
        if (pSlow != pFast) {
            return NULL;
        }


        pSlow = head;
        while (pSlow != pFast) {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pSlow;
    }
};