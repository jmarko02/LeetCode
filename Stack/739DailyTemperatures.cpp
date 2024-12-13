#include <vector>
#include <stack>
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> st;
        std::vector<int> result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int ind = st.top();
                st.pop();
                result[ind] = i - ind;
            }
            st.push(i);
            
        }
        return result;
    }
};