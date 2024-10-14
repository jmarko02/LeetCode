#include<algorithm>
#include<vector>
#include<unordered_set>
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> mySet = std::unordered_set<int>(nums.begin(), nums.end());
        int max_len = 0;
        for(const auto& num : mySet) 
        {
            if(mySet.find(num-1) == mySet.end())
            {
                int curr_len = 0;
                while(mySet.find(num + curr_len) != mySet.end())
                {
                    curr_len++;
                }
                max_len = std::max(max_len,curr_len);
            }
        }
        return max_len;
    }
};