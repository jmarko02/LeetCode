#include<vector>
#include<queue>
using namespace std;
class Solution {
private:
    vector<vector<int>> directions = { {1, 0}, {-1, 0}, {0, 1} , {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int minutes = 0;
        int fresh = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        while(fresh > 0 && !q.empty()) {
            int size = q.size();
            for(int k = 0; k < size; k++){
                
                pair<int,int> p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();
                for(int m = 0; m < 4; m++){
                    int row = i + directions[m][0];
                    int col = j + directions[m][1];
                    if(row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] != 1) continue;
                    grid[row][col] = 2;
                    q.push({row,col});
                    fresh--;
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};
/*
class Solution {
private:
    vector<vector<int>> directions = { {1, 0}, {-1, 0}, {0, 1} , {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<tuple<int,int,int>> q;
        int minutes = 0;
        int fresh = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2)
                    q.push(make_tuple(i,j,0));
                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        while(!q.empty()){
            auto [i, j, min] = q.front();
            q.pop();
            minutes = min;
            for(int k = 0; k < 4; k++){
                int row = i + directions[k][0];
                int col = j + directions[k][1];
                if(row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] != 1) continue;
                grid[row][col] = 2;
                fresh--;
                q.push(make_tuple(row, col, min + 1));
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};
*/
