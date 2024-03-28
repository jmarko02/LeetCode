/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        /* O(nlogn), space: O(1)
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1;i++){
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    `   */  
        std::unordered_map<int,int> hashset;
        for(auto elem : nums) hashset[elem]++;

        for(auto elem : hashset) 
            if (elem.second >1 ) return true;
        return  false;
    }
};
