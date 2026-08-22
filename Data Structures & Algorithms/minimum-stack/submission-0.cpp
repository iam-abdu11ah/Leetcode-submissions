class MinStack {
private:
    stack<int> st;
    stack<int> st2;
public:
    MinStack() {
        
    }
    //  1   2   3   
    void push(int val) {
        if(st.size()==0){
            st2.push(val);
        }else{
            int e=st2.top();
            if(val<e) st2.push(val);
            else st2.push(e);
        }
        st.push(val);
    }
    
    void pop() {
        if(st.size()>0){
            st.pop();
            st2.pop();
        }
    }
    
    int top() {
        if(st.size()>0)
            return st.top();
        return -1;
    }
    
    int getMin() {
        return st2.top();
    }
};
