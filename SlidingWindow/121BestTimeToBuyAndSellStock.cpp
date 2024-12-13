#include<algorithm>
#include<vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int l = 0;
        int r = 1;
        int max_profit = 0;
        while(r < prices.size()){
            if(prices[l] < prices[r]){
                int profit = prices[r] - prices[l];
                max_profit = std::max(max_profit, profit);
            } else{
                l = r;
            }
            r++;
        }
        return max_profit;
    }
};