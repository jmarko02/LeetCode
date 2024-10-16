#include<algorithm>
#include<vector>
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        int l = 0;
        int r = height.size()-1;
        while(l < r){
            int h = std::min(height[l], height[r]);
            int curr = h * (r-l);
            max_water = std::max(curr,max_water);
            if(h == height[l]) l += 1;
            else r -= 1;
        }
        return max_water;
    }
};