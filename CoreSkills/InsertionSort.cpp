// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> vec;
        for(int i = 0; i <pairs.size(); i++){
            for(int j = i-1; j>=0 && pairs[j].key > pairs[j+1].key; j--){
                Pair* p = new Pair(pairs[j].key, pairs[j].value);
                pairs[j].key = pairs[j+1].key;
                pairs[j].value = pairs[j+1].value;
                pairs[j+1].key = p->key;
                pairs[j+1].value = p->value;
            }
            vec.push_back(pairs);
        }
        return vec;
    }
};
