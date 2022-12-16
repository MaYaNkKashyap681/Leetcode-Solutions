class MyQueue {
        stack<int> s1;
        stack<int> s2;
public:
    MyQueue() {
    
    }
    
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int x = -1;
        if(!s1.empty()) {
            x = s1.top();
            s1.pop();
        }
        return x;
    }
    
    int peek() {
          int x = -1;
        if(!s1.empty()) {
            x = s1.top();
        }
        return x;
    }
    
    bool empty() {
        return s1.empty();
    }
};
