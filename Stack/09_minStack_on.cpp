class MinStack {
public: 
    stack<int>st;
    stack<int>support;
    
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(support.empty() || support.top()>=x){
            support.push(x);
        }
    }
    
    void pop() {
        if(support.top()==st.top()){
            support.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return support.top();
    }
};
