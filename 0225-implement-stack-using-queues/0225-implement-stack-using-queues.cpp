class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
      
    }
    
    void push(int x) {
        while(q1.size()>0){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(q2.size()>0){
            q1.push(q2.front());
            q2.pop();
        }
        // Using one queue
        // q1.push(x);
        // int v = q1.size()-1;
        // int i = 0;
        // while(i<v){
        //     q1.push(q1.front()); // Elements r added to the rear end
        //     i++;
        //     q1.pop(); // Element r removed from front end
        // }
    }
    
    int pop() {
        int ele = q1.front();
        q1.pop();
        return ele;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */