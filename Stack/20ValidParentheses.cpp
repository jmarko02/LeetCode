#include<unordered_map>
#include<stack>
#include<string>
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> myStack;
        std::unordered_map<char,char> myMap;
        myMap['}'] = '{';
        myMap[')'] = '(';
        myMap[']'] = '['; 
        for(char c : s){
            if(myMap.count(c) == 0){
                myStack.push(c);
            } else {
                if(myStack.empty() || myMap[c] != myStack.top() ){
                    return false;
                }
                myStack.pop();
            }
        }
        return myStack.empty();
    }
};
