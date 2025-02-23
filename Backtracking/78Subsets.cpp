using namespace std;
#include<vector>
class Solution {
    public:
        vector<vector<int>> result;
        vector<int> subset;
    
        vector<vector<int>> subsets(vector<int>& nums) {
            dfs(0, nums);
            return result;
        }
    
        void dfs(int index, vector<int>& nums){
            if(index >= nums.size()){
                result.push_back(subset);
                return;
            }
    
            subset.push_back(nums[index]);
            dfs(index + 1, nums);
    
            subset.pop_back();
            dfs(index + 1, nums);
        }
    };