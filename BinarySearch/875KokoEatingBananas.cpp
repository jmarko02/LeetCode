#include <vector>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        size_t l = 1;
        size_t r = 0;
        // size_t result = 0;
        for(size_t pile : piles){
            r = max(r, pile);
        }

        while(l <= r){
            size_t k = l + ( r - l ) / 2;
            size_t hrs = 0;
            for(size_t pile: piles){
                hrs += (pile + k - 1) / k;
            }
            if(hrs <= h)
            {
                //result = h;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        //return result;
        return l;
    }
};
