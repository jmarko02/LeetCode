#include<stack>
#include<algorithm>
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        int current_min = std::min(
            val,
            minStack.empty() ? val : minStack.top()
        );
        minStack.push(current_min);
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }

private:
    std::stack<int> stack;
    std::stack<int> minStack;
    
};
