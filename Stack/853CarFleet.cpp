#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back(std::pair<int,int>(position[i], speed[i]));
        }
        std::sort(cars.rbegin(), cars.rend());
        vector<double> stack;

        for(const auto& car : cars){
            stack.push_back((double)(target - car.first) / car.second);
            if(stack.size() >= 2 && stack.back() <= stack[stack.size() - 2]) {
                stack.pop_back();
            } 
        }
        return stack.size();
    }
};