#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        int search2Dmatrix(vector<vector<int>>& matrix, int target){
            int ROWS = matrix.size();
            int COLS = matrix[0].size();

            int top = 0, bot = COLS - 1;
            while (top <= bot){
                int row = (top + bot) / 2;
                if (matrix[row][COLS - 1] < target){
                    top = row + 1;
                }
                else if (matrix[row][0] > target){
                    bot = row - 1;
                }
                else{
                    break;
                }
            }

            if (!(top <= bot)){
                return false;
            }

            int row = (top + bot) / 2;
            int left = 0, right = COLS - 1;
            while (left <= right){
                int mid = (left + right) / 2;
                if (matrix[row][mid] < target){
                    left = mid + 1;
                }
                else if (matrix[row][mid] > target){
                    right = mid - 1;
                }
                else{                                           //same as condition of matrix[row][mid] == target
                    return true;
                }
            }
            return false;
        }
};