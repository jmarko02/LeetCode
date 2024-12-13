
#include<vector>
#include<queue>
using namespace std;
class Solution {
private:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0) q.push({i,j});
            }
        }

        while(!q.empty()){
            pair<int,int> p = q.front();
            int i = p.first;
            int j = p.second;
            q.pop();
            for(int k = 0 ; k < 4; k++){
                int ii = directions[k][0];
                int jj = directions[k][1];
                if((i+ii) < 0 || (j+jj) < 0 ||
                    (i+ii) >= rows || (j+jj) >= cols ||
                    grid[i+ii][j+jj] != INT_MAX ) 
                        continue;
                grid[i + ii][j + jj] = grid[i][j] + 1;
                q.push({i+ii, j+jj});
            }
        }
    }
};
