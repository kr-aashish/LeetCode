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
    ListNode* reverseList(ListNode* head) 
    {
        // if(head==NULL or head->next==NULL) return head; //Auto handled!
        
        ListNode *prev = NULL, *curr = head, *nxt;
        while(curr!=NULL)
        {
            nxt = curr->next;
            
            curr->next = prev;
            
            prev = curr; curr = nxt;
        }
        return prev;
    }
};