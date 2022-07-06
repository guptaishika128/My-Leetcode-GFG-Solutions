class MyQueue {
public:
    stack<int> s1,s2;
    int count = 0;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
      
    }
    
    int pop() {
        int res = peek();
        s2.pop();
        return res;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        
        return res;
    }
    
    bool empty() {
          return s1.empty()&&s2.empty();
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