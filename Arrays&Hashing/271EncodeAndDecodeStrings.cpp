#include<string>
#include<vector>
#include <iostream>
class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
        std::string result = "";
        for(const auto& s:strs){
            result += std::to_string(s.size()) + "#" + s;
        }
        return result;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> result;
        int i = 0;
        size_t j = 0;
        while(i < s.size()){
            j = s.find_first_of('#', i);
            size_t len = stoull(s.substr(i, j-i));
            result.push_back(s.substr(j+1,len));
            i = j + len + 1;
        }
        return result;
    }
};
