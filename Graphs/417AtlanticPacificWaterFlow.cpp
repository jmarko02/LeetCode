using namespace std;
#include<vector>
class Solution {
    public:
            vector<pair<int,int>> dirs = {{1,0},{ -1, 0},{0,1},{0, -1}};
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
           int rows = heights.size();
           int cols = heights[0].size(); 
           vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
           vector<vector<bool>> atlantic(rows, vector<bool>(cols,false));
           vector<vector<int>> result;
    
           for(int r = 0 ; r < rows; r++){
                dfs(r ,0 , pacific, heights);
                dfs(r, cols - 1, atlantic, heights);
           }
    
           
           for(int c = 0 ; c < cols; c++){
                dfs(0, c , pacific, heights);
                dfs(rows - 1, c, atlantic, heights);
           }  
    
           for(int r = 0; r < rows; r++ ){
                for (int c = 0; c < cols; c++){
                    if(pacific[r][c] && atlantic[r][c])
                        result.push_back({r,c});
                }
           }
           return result;
        }
    
        void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
            ocean[r][c] = true;
            for(auto [dr, dc] : dirs){
                int nr = r + dr;
                int nc = c + dc;
                if(nr >=0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c])
                    dfs(nr, nc, ocean, heights);
            }
        }
    };