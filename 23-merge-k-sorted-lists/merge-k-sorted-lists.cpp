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
    ListNode *mergeTwoLists(ListNode *headOne, ListNode *headTwo) {
        if (!headOne) 
            return headTwo;
        if (!headTwo)
            return headOne;

        if (headOne->val <= headTwo->val) {
            headOne->next = mergeTwoLists(headOne->next, headTwo);
            return headOne;
        } else {
            headTwo->next = mergeTwoLists(headOne, headTwo->next);
            return headTwo;
        }
    }

    ListNode *mergeLists(int l, int r, vector<ListNode*> lists) {
        if (l > r)
            return NULL;

        if (l == r)
            return lists[l];

        int mid = (l + r) / 2;
        return mergeTwoLists(mergeLists(l, mid, lists), mergeLists(mid + 1, r, lists));
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists(0, int(lists.size()) - 1, lists);
    }
};