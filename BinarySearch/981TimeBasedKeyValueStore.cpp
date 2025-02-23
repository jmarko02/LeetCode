#include<vector>
#include<unordered_map>
using namespace std;
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        auto& arr = map[key];
        int l = 0;
        int r = arr.size() - 1;
        string result = "";
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(arr[mid].first > timestamp) r = mid - 1;
            else {
                result = arr[mid].second;
                l = mid + 1;
            }
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */