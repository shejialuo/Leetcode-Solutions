/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  bool checkRow(vector<vector<char>> &board) {
    for (auto &&row : board) {
      unordered_set<char> visited{};
      for (auto c : row) {
        if (c != '.') {
          if (visited.count(c)) {
            return false;
          }
          visited.insert(c);
        }
      }
    }
    return true;
  }

  bool checkCol(vector<vector<char>> &board) {
    for (int j = 0; j < board[0].size(); j++) {
      unordered_set<char> visited{};
      for (int i = 0; i < board.size(); i++) {
        if (board[i][j] != '.') {
          if (visited.count(board[i][j])) {
            return false;
          }
          visited.insert(board[i][j]);
        }
      }
    }
    return true;
  }

  bool checkSubBox(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); i += 3) {
      for (int j = 0; j < board[0].size(); j += 3) {
        unordered_set<char> visited{};
        for (int k = i; k < i + 3; k++) {
          for (int l = j; l < j + 3; l++) {
            if (board[k][l] != '.') {
              if (visited.count(board[k][l])) {
                return false;
              }
              visited.insert(board[k][l]);
            }
          }
        }
      }
    }
    return true;
  }

public:
  bool isValidSudoku(vector<vector<char>> &board) {
    if (!checkRow(board)) {
      return false;
    }
    if (!checkCol(board)) {
      return false;
    }
    if (!checkSubBox(board)) {
      return false;
    }
    return true;
  }
};
// @lc code=end
