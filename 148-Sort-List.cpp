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
    ListNode *mergeLinkedLists(ListNode *listOne, ListNode *listTwo) {
        if (!listOne) 
            return listTwo;
        if (!listTwo) 
            return listOne;

        if (listOne->val <= listTwo->val) {
            listOne->next = mergeLinkedLists(listOne->next, listTwo);
            return listOne;
        } else {
            listTwo->next = mergeLinkedLists(listOne, listTwo->next);
            return listTwo;
        }
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head or !head->next)
            return head;

        ListNode *curr = head, *mid = head;
        int cnt = 0;
        while (curr) {
            if (cnt % 2)
                mid = mid->next;
            curr = curr->next;
            cnt++;
        }

        curr = head;
        while (curr->next != mid)
            curr = curr->next;
        curr->next = NULL;

        return mergeLinkedLists(sortList(head), sortList(mid));
    }
};