#include<set>
#include<algorithm>
#include<string>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int l = 0 ;
        int res = 0;
        std::set<int> mySet;

        for(int r = 0 ; r < s.size(); r++)
        {
            while(mySet.find(s[r]) != mySet.end())
            {
                mySet.erase(s[l]);
                l++;
            }
            mySet.insert(s[r]);
            res = std::max(res, r - l + 1 );
        }
        return res;
    }
};