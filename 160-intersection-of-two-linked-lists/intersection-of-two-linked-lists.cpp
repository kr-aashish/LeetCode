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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currOne = headA, *currTwo = headB;
        while (currOne != currTwo) {
            currOne = currOne ? currOne->next : headB;
            currTwo = currTwo ? currTwo->next : headA;
        }
        return currOne;
    }
};