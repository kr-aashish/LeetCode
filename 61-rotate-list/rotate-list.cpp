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
#define f(i,n) for(int i=0; i<n; i++)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL or head->next==NULL) return head;
        
        int N = 0; ListNode *curr = head;
        while(curr)
        {
            curr = curr->next;
            N++;
        }
        k %= N;
        if(k==0) return head;
        
        curr = head;
        f(i,N-k-1) curr = curr->next;
        ListNode* last = curr;
        
        ListNode *newhead = curr->next;
        
        while(curr->next) curr = curr->next;
        curr->next = head;
        last->next = NULL;
        
        return newhead;
    }
};