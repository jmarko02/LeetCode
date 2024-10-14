#include<vector>
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) 
    {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool squares[9][9] = {false};

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue;
                int square = (i/3) * 3 + (j/3);
                int ind = board[i][j] - '0' - 1;
                if(rows[i][ind] || cols[j][ind] || squares[square][ind] ) return false;
                rows[i][ind] = true;
                cols[j][ind] = true;
                squares[square][ind] = true;
            }
        }
        return true;
    }
};