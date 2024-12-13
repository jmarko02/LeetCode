#include<vector>
#include<string>
class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::vector<int> counts(128,0);
        for(char c : t) counts[c]++;
        int begin = 0, end = 0, head = 0, len = INT_MAX, count = t.size();

        while(end < s.size())
        {
            if(counts[s[end++]]-- > 0)
                count--;
            while(count == 0)
            {
                if(len > end - begin) 
                {
                    len = end - begin;
                    head = begin;
                }
                
                if(counts[s[begin++]]++ == 0) 
                    count++;
            }
        }
        return len == INT_MAX ? "" : s.substr(head,len);
    }
};