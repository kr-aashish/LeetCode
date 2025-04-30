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
    ListNode* splitList(ListNode* head) {
        auto pFast = head;
        auto pSlow = head;

        while (pFast and pFast->next) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }

        auto mid = pSlow->next;
        pSlow->next = NULL;

        return mid;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* currNode = head;
        ListNode* prevNode = NULL;

        while (currNode) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        return prevNode;
    }

    void mergeAlternate(ListNode* headOne, ListNode* headTwo) {
        while (headOne and headTwo) {
            auto nextOne = headOne->next;
            auto nextTwo = headTwo->next;

            headOne->next = headTwo;
            headTwo->next = nextOne;

            headOne = nextOne;
            headTwo = nextTwo;
        }
    }

public:
    void reorderList(ListNode* head) {
        if (!head or !head->next) {
            return;
        }

        ListNode* mid = splitList(head);
        ListNode* reversedMid = reverseList(mid);
        mergeAlternate(head, reversedMid);
    }
};