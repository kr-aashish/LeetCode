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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        auto currNode = head;

        while (currNode) {
            int counter = m - 1;
            while (counter--) {
                currNode = currNode->next;

                if (!currNode) {
                    return head;
                }
            }
            auto node = currNode;

            int deleteCounter = n + 1;
            while (deleteCounter--) {
                currNode = currNode->next;

                if (!currNode) {
                    node->next = NULL;
                    return head;
                }
            }
            node->next = currNode;
        }

        return head;
    }
};