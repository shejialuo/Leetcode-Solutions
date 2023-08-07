/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  bool helper(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == '.') {
          for (char k = '1'; k <= '9'; k++) {
            if (isValid(i, j, k, board)) {
              board[i][j] = k;
              if (helper(board))
                return true;
              board[i][j] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }
  bool isValid(int row, int col, char val, vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      if (board[row][i] == val) {
        return false;
      }
    }
    for (int j = 0; j < 9; j++) {
      if (board[j][col] == val) {
        return false;
      }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
      for (int j = startCol; j < startCol + 3; j++) {
        if (board[i][j] == val) {
          return false;
        }
      }
    }
    return true;
  }

public:
  void solveSudoku(vector<vector<char>> &board) { helper(board); }
};
// @lc code=end
