/*
Link: https://leetcode.com/problems/implement-queue-using-stacks/description/
Method: Extra array
Time Complexity: 
Space Complexity: O(n) 
*/

class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                int x = s1.top();
                s2.push(x);
                s1.pop();
            }
        }        
        int ans = s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()) {
                int x = s1.top();
                s2.push(x);
                s1.pop();
            }
        }        
        int ans = s2.top();
        return ans;
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
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