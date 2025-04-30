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
        if (!head or !head->next) { // len 0 or len 1 -> no cycle
            return NULL;
        }

        ListNode* pSlow = head;
        ListNode* pFast = head;

        while (pFast and pFast->next) { // pFast check also needed
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