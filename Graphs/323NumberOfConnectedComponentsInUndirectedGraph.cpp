
#include<vector>
using namespace std;
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit = vector<bool>(n,false);

        for(const auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int connected = 0;

        for(int node = 0; node < n; node++){
            if(!visit[node]){
                dfs(node,visit,adj);
                connected++;
            }
        }
        return connected;
    }
    void dfs(int node, vector<bool>& visit, vector<vector<int>>& adj){
        
        visit[node] = true;
        for(int n : adj[node]){
            if(!visit[n]){
                dfs(n, visit, adj);
            }
        }
    }
};
