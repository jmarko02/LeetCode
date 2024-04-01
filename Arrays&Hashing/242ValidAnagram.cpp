#include <string>
// #include<unordered_map>
#include<algorithm>
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        //O(nlogn) time, O(1) space:
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;

        /* O(n) 

        std::unordered_map<char,int> my_map_s;
        if(s.length() != t.length()) return false;
        for(int i = 0 ; i < s.length(); i++){
            my_map_s[s[i]]++;
        }
        for(int i = 0 ; i < t.length(); i++){
            my_map_s[t[i]]--;
        }
        for (auto p : my_map_s){
            if(p.second != 0) return false;
        }
        return true;
        */

    }
};