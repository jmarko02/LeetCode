#include<cctype>
#include<string>
class Solution {
public:
    bool isPalindrome(std::string s) {
        
        int start = 0;
        int end = s.size()-1;
        while(start < end){
            while(start < end && !std::isalnum(s[start])) 
                start++;
            while(start < end && !std::isalnum(s[end])) 
                end--;
            if(std::tolower(s[start]) != std::tolower(s[end])) 
                return false;
            start++;
            end--;
        }
        return true;
    }

};
