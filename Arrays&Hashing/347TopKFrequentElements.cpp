#include<vector>
#include<unordered_map>
#include<algorithm>
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> m;
        std::vector<std::pair<int,int>> pairs;

        for( int i = 0 ; i < nums.size() ; i++){
            m[nums[i]]++;
        }
        for(const auto& p : m){
            pairs.push_back(std::make_pair(p.second, p.first));
        }
        sort(pairs.begin(), pairs.end());
        std::vector<int> ret;
        for(auto p = pairs.rbegin(); p != pairs.rend(); p++){
            ret.emplace_back(p->second);
            k--;
            if(k==0) break;
        }
        return ret;
    }
};