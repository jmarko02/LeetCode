/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
       
        std::unordered_map<int,int> hashset;
        for(auto elem : nums){
            hashset[elem]++;
            if(hashset[elem] > 1) return true;
        } 
        return  false;
    }
};
