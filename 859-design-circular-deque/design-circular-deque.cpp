class MyCircularDeque {
    int maxSize, currSize;
    struct ListNode {
        int val;
        ListNode *next, *prev;

        //note the 3 standard constructors
        ListNode() : val(0), prev(NULL), next(NULL) {}
        ListNode(int value) : val(value), prev(NULL), next(NULL) {}
        ListNode(int value, ListNode *prev, ListNode *next) : val(value), 
        prev(prev), next(next) {}
    };
    ListNode *head, *tail;

public:
    MyCircularDeque(int k) {
        maxSize = k, currSize = 0;
        head = tail = NULL;
    }
    
    bool insertFront(int value) {
        if (currSize == maxSize)
            return false;

        if (!currSize) {
            head = tail = new ListNode(value, head, head);
        } else { 
            ListNode *newNode = new ListNode(value);
            head->prev = newNode, newNode->next = head;
            tail->next = newNode, newNode->prev = tail;
            head = newNode;
        }

        currSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if (currSize == maxSize)
            return false;

        if (!currSize) {
            head = tail = new ListNode(value, head, head);
        } else { 
            ListNode *newNode = new ListNode(value);
            tail->next = newNode, newNode->prev = tail;
            head->prev = newNode, newNode->next = head;
            tail = newNode;
        }
        
        currSize++;
        return true;
    }
    
    bool deleteFront() {
        if (!currSize)
            return false;

        ListNode *toDelete = head;

        if (currSize == 1) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }

        delete(toDelete);
        currSize--;
        return true;
    }
    
    bool deleteLast() {
        if (!currSize)
            return false;

        ListNode *toDelete = tail;

        if (currSize == 1) {
            tail = head = NULL;
        } else { //circular note
            tail = tail->prev;
            tail->next = NULL;
        }

        delete(toDelete);
        currSize--;
        return true;
    }
    
    int getFront() {
        if (!currSize)
            return -1;
        return head->val;
    }
    
    int getRear() {
        if (!currSize)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */