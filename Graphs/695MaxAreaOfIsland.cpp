#include<vector>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int newArea = 0;
                    dfs(i, j, grid, newArea);
                    maxArea = std::max(maxArea, newArea);
                }
            }
        }
        return maxArea;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, int& newArea){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return;
        newArea += (int)grid[i][j];
        grid[i][j] = 0;

        dfs(i+1, j, grid, newArea);
        dfs(i-1, j, grid, newArea);
        dfs(i, j+1, grid, newArea);
        dfs(i, j-1, grid, newArea);
    }
};
