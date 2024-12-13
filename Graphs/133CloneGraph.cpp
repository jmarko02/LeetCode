
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#include<unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<Node*, Node*> m;
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
    Node* dfs(Node* node){
        if(!node) return nullptr;
        if(m.count(node)) return m[node];

        Node* copy = new Node(node->val);
        m[node] = copy;
        for(Node* n : node->neighbors){
            copy->neighbors.push_back(dfs(n));
        }
        return copy;
    }
    
};
