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
    bool hasCycle(ListNode *head) {
        ListNode *pSlow = head, *pFast = head;
        while (pFast and pFast->next) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;

            if (pSlow == pFast)
                return true;
        }

        return false;
    }
};