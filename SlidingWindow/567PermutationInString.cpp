#include<vector>
#include<string>
class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if(s1.size() > s2.size()) return false;
        if(s1.size() == 0) return false;

        std::vector<int> s1_vec(26,0), s2_vec(26,0);
        for(char c: s1){
            s1_vec[c - 'a']++;
        }
        int window = s1.size();
        for(int i = 0; i < window ; i++){
            s2_vec[s2[i] - 'a']++;
        }
        if(s1_vec == s2_vec) return true;
        for(int i = window; i < s2.size(); i++){
            s2_vec[s2[i] - 'a']++;
            s2_vec[s2[i-window] - 'a']--;
            if(s1_vec == s2_vec) return true;
        }
        return false;
    }
};