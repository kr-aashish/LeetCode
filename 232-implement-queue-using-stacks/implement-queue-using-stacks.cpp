class MyQueue {
public:
    stack<int> stackOne, stackTwo;
    int topValue;
    MyQueue() {
    }
    
    void push(int x) {
        if (stackOne.empty())
            topValue = x;
        stackOne.push(x);
    }
    
    int pop() {
        if (stackTwo.empty()) {
            while (!stackOne.empty()) {
                stackTwo.push(stackOne.top());
                stackOne.pop();
            }
        }
        int poppedVal = stackTwo.top();
        stackTwo.pop();
        return poppedVal;
    }
    
    int peek() {
        if (!stackTwo.empty())
            return stackTwo.top();
        else 
            return topValue;
    }
    
    bool empty() {
        return stackOne.empty() and stackTwo.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */