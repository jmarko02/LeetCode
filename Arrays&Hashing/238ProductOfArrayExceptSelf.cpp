#include<vector>
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int pre = 1;
        std::vector<int> result;
        for(const auto& num : nums){
            result.push_back(pre);
            pre *= num;
        }
        int post = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            result[i] *= post;
            post *= nums[i];
        }
        return result;
    }
};