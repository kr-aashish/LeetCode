class CustomStack {
    int maximumSize;
    vector<pair<int,int>> customStack;

public:
    CustomStack(int maxSize) {
        // customStack.resize(maxSize); -> no resize here
        customStack.clear();
        maximumSize = maxSize;
    }
    
    void push(int x) {
        if (customStack.size() < maximumSize) 
            customStack.push_back(make_pair(x, 0));
    }
    
    int pop() {
        if (customStack.empty())
            return -1;

        auto lastVal = customStack.back();
        customStack.pop_back();

        if (!customStack.empty()) 
            customStack.back().second += lastVal.second;

        return lastVal.first + lastVal.second;
    }
    
    void increment(int k, int val) {
        // if (k > customStack.size())
        //     customStack.back().second += val;
        // else if (!customStack.empty())   
        //     customStack[k - 1].second += val;
        //-> you need to check not empty operation in both the cases!!

        if (customStack.size() > k) 
            customStack[k - 1].second += val;
        else if (!customStack.empty())
            customStack.back().second += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */