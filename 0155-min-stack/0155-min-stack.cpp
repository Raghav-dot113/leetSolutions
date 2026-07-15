class MinStack {
public:
    stack<pair<int,long long>> s;
   
    long long minVal = INT_MAX;
    MinStack() {
    }
    
    void push(long long value) {
        if(s.empty()) minVal = INT_MAX;
        if(minVal >= value){
            minVal = value;
        }
        s.emplace(value,minVal);
    }
    
    void pop() {
        s.pop();
        if(!s.empty()) minVal = s.top().second;

    }
    
    int top() {
        return s.top().first;
    }
    
    long long getMin() {
        
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */