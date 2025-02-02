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
    ListNode *strt, *en;
    
    void reverseK(ListNode *newhead, int K, ListNode* &head)
    {
        ListNode *prev = NULL, *curr = newhead, *nxt;
        
        int cnt = 0;
        while(curr!=NULL and cnt<K)
        {
            nxt = curr->next;
            
            curr->next= prev;
            
            prev = curr; curr = nxt; cnt++;           
        }
        
        if(strt!=NULL) strt->next = prev;
        else head = prev;
        newhead->next = en;
        
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left==1) strt = NULL;
        else
        {
            strt = head;
            f(i,left-2)
            {
                strt = strt->next;
            }
        }
        
        en = head;
        f(i,right)
        {
            en = en->next;
        }
             
        if(strt==NULL) reverseK(head, right-left+1, head);
        else if(strt->next!=NULL) reverseK(strt->next, right-left+1, head);
        
        return head;
    }
};