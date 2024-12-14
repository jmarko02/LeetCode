#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = (r + l) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) r = mid-1;
            else l = mid + 1;
        }
        return -1;
    }
};
