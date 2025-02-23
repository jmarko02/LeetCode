#include<vector>
#include<queue>
using namespace std;
using type = pair<double, vector<int>>;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<type> distances;

        for(vector<int>& point : points){
            distances.push({sqrt(pow(point[0],2) + pow(point[1],2)), point});
             if(distances.size() > k){
                distances.pop(); //popping largest distances
            }
        } 

        vector<vector<int>> res;
        for(int i = 0; i < k; i++){
            vector<int> point = distances.top().second;
            distances.pop();
            res.push_back(point);
        }
        return res;
    }
};
