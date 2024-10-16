#include<algorithm>
#include<vector>
class Solution {
public:
    int trap(std::vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_left = height[l];
        int max_right = height[r];
        int res = 0;
        while(l < r)
        {
            if(max_left < max_right)
            {
                l++;
                max_left = std::max(max_left,height[l]);
                res += max_left - height[l];
            } else 
            {
                r--;
                max_right = std::max(max_right, height[r]);
                res += max_right - height[r];
            }
        }
        return res;
    }
};