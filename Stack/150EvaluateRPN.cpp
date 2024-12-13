#include<stack>
#include<string>
#include<vector>
class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;
        for(const auto& t : tokens){
            if(t == "+"){
                int val2 = stack.top();
                stack.pop();
                int val1 = stack.top();
                stack.pop();
                stack.push(val1 + val2);
            } else if ( t == "-") {
                int val2 = stack.top();
                stack.pop();
                int val1 = stack.top();
                stack.pop();
                stack.push(val1 - val2);
            } else if( t == "*") {
                int val2 = stack.top();
                stack.pop();
                int val1 = stack.top();
                stack.pop();
                stack.push(val1 * val2);
            } else if( t == "/"){
                int val2 = stack.top();
                stack.pop();
                int val1 = stack.top();
                stack.pop();
                stack.push(val1 / val2);
            } else {
                stack.push(std::stoi(t));
            }
        }
        return stack.top();
    }

};