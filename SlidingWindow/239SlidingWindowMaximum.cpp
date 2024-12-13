#include<vector>
#include<deque>
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> counts;
        int count = 0, r = 0 , l = 0;
        std::vector<int> output;
        while(r < nums.size()){
            while(!counts.empty() && nums[r] > nums[counts.back()]){
                counts.pop_back();
            }
            counts.push_back(r);
            if(l > counts[0]) counts.pop_front();
            if(r+1 >= k) {
                output.push_back(nums[counts[0]]);
                l++;
            }
            r++;
        }
        return output;
    }
};