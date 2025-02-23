#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int,int>> stack;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!stack.empty() && stack.top().second > heights[i]){
                auto pair = stack.top();
                stack.pop();
                maxArea = max(maxArea, pair.second * (i - pair.first));
                start = pair.first;
            }
            stack.push(pair<int,int>(start, heights[i]));
        }
        while(!stack.empty()){
            auto pair = stack.top();
            stack.pop();
            maxArea = max(maxArea, pair.second * static_cast<int>((heights.size() - pair.first)));
        }
        return maxArea;
    }
};