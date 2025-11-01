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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> numsToTemove(nums.begin(), nums.end());

        ListNode* currNode = head;

        while (currNode) {
            ListNode* node = currNode->next;
            while (node and 
                numsToTemove.count(node->val)) {
                node = node->next;
            }
            currNode->next = node;
            currNode = currNode->next;
        }

        auto toPrint = head;
        while (toPrint) {
            cout << toPrint->val << " ";
            toPrint = toPrint->next;
        }

        if (head and numsToTemove.count(head->val)) {
            head = head->next;
        }

        return head;
    }
};