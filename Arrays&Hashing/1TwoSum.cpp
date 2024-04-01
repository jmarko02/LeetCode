#include<unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int,int> m;
        for(int i = 0 ; i < nums.size(); i++){
            int existing = target - nums[i];
            if(m.count(existing)) return {m[existing],i};
            m[nums[i]] = i;
        }
        return {-1,-1};
    }
};