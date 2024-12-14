#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int t = 0;
        int b = matrix.size() - 1;
        int row = -1;
        while( t <= b) {
            int row_mid = t + (b - t ) / 2;
            if(matrix[row_mid][0] > target ) b = row_mid - 1;
            else if (row_mid < matrix.size() - 1 && matrix[row_mid + 1][0] <= target )  t = row_mid + 1;
            else {
                row = row_mid;
                break;
            }
        }
        if (row == -1) return false;
        int l = 0; 
        int r = matrix[row].size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(matrix[row][mid] > target) r = mid - 1;
            else if (matrix[row][mid] < target) l = mid + 1;
            else return true;
        }
            
        return false;
    }
};
