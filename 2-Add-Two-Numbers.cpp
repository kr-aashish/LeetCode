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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head = NULL;
        ListNode *curr = NULL;
        
        int carry = 0;
        while(l1 and l2)
        {
            int sum = l1->val + l2->val;
            sum += carry;
            
            carry = sum/10; sum %= 10;
            ListNode *n = new ListNode;
            n->val = sum;
            // cout<<sum<<" ";
            
            if(head==NULL)
            {
                head = n;
                curr = head;
            }
            else
            {
                curr->next = n;
                curr = curr->next;
            }                
            
            l1 = l1->next; l2 = l2->next;
        }

        while(l1)
        {
            int sum = l1->val;
            sum += carry;
            
            carry = sum/10; sum %= 10;
            ListNode *n = new ListNode;
            n->val = sum;
            curr->next = n; curr = curr->next;
            
            l1 = l1->next;
        }
        
        while(l2)
        {
            int sum = l2->val;
            sum += carry;
            
            carry = sum/10; sum %= 10;
            ListNode *n = new ListNode;
            n->val = sum;
            curr->next = n; curr = curr->next;
            
            l2 = l2->next;
        }
        
        while(carry)
        {
            int sum = carry;
            
            carry = sum/10; sum %= 10;
            ListNode *n = new ListNode;
            n->val = sum;
            curr->next = n; curr = curr->next;   
        }
        
        curr->next = NULL;
        
        return head;
    }
};