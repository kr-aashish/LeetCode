class MinStack {
private:
    std::stack<std::pair<int, int>> stack;

public:
    MinStack() {}

    void push(int x) {
        if (stack.empty()) {
            stack.push({x, x});
            return;
        }

        int currentMin = stack.top().second;
        stack.push({x, std::min(x, currentMin)});
    }

    void pop() { stack.pop(); }

    int top() { return stack.top().first; }

    int getMin() { return stack.top().second; }
};