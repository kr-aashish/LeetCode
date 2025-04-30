/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }

        Node* currNode = head;
        while (currNode) {
            currNode->next = new Node(currNode->val, currNode->next);
            currNode = currNode->next->next;
        }

        currNode = head;
        while (currNode) {
            currNode->next->random = currNode->random ? currNode->random->next : NULL;
            currNode = currNode->next->next;
        }

        Node* X = head;
        Node* Y = head->next;
        Node* newHead = head->next;
        while (Y) {
            X->next = Y->next;
            X = Y;
            Y = Y->next;
        }

        return newHead;
    }
};