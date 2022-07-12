/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] Word Search
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
  bool existHelper(vector<vector<char>>& board, int i, int j, string& word) {
    if(word.size() == 0) return true;
    int m = board.size(), n = board[0].size();
    if (i >= m || i < 0 || j >= n || j < 0 || board[i][j] != word[0]) return false;
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ans = existHelper(board, i + 1, j, s)
            || existHelper(board, i - 1, j, s)
            || existHelper(board, i, j + 1, s)
            || existHelper(board, i, j - 1, s);
    board[i][j] = c;
    return ans;

  }
public:
  bool exist(vector<vector<char>>& board, string word) {

    for(int i = 0; i < board.size(); ++i) {
      for(int j = 0; j < board[0].size(); ++j) {
        if(existHelper(board, i, j, word))
          return true;
      }
    }
    return false;
  }
};
// @lc code=end

