#include<vector>
#include<unordered_map>

class Solution {
    public:
        std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs){
            std::unordered_map<std::string, std::vector<std::string>> m;
            std::vector<std::vector<std::string>> vec;

            for(std::string s : strs){
                std::string key (26,0);
                for(char c : s){
                    key[c-'a']++;
                }
                m[key].push_back(s);
            }
            
            for(auto k : m){
                vec.push_back(k.second);
            }

            return vec;
        }
};