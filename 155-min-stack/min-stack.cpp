const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class MinStack {
public:
    int mini = INT_MAX;
    stack<int>st;

    MinStack() {}
    
    void push(int val) {
        if(val<=mini){
            st.push(mini);
            mini=val;
        }
        st.push(val);
    }
    
    void pop() {
        if(mini==st.top()){
            st.pop();
            mini=st.top();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */