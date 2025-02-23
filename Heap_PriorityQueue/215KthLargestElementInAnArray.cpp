#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> maxHeap;
        for(const auto& el : nums){
            maxHeap.push(el);
            if(maxHeap.size() > k) 
                maxHeap.pop();
        }
        return maxHeap.top();
    }
};