/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  class DisjointSet {
  private:
    vector<int> data;
    vector<int> rank;

  public:
    DisjointSet(int n) {
      data.resize(n);
      for (int i = 0; i < n; ++i) {
        data[i] = i;
      }
      rank.resize(n);
      fill(rank.begin(), rank.end(), 0);
    }

    int root(int i) {
      while (i != data[i]) {
        data[i] = data[data[i]];
        i = data[i];
      }
      return i;
    }

    void connect(int i, int j) {
      int rootI = root(i);
      int rootJ = root(j);

      if (rootI != rootJ) {
        data[rootI] = rootJ;
      }
    }

    bool isConnect(int i, int j) { return root(i) == root(j); }
  };

  bool isValidForDFS(int i, int j, int m, int n) {
    return i >= 1 && i < m - 1 && j >= 1 && j < n - 1;
  }

  bool iSValidForUnion(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
  }

  void dfsSolutionHelper(vector<vector<char>> &board, int i, int j, int m,
                         int n, bool isBoarder = false) {
    if (!isBoarder) {
      board[i][j] = '0';
    }
    for (int k = 0; k < 4; ++k) {
      int nextI = i + dirs[k][0];
      int nextJ = j + dirs[k][1];
      if (isValidForDFS(nextI, nextJ, m, n) && board[nextI][nextJ] == 'O') {
        dfsSolutionHelper(board, nextI, nextJ, m, n);
      }
    }
  }

public:
  /**
   * @brief We could traverse from the boarder. It
   * is a simple idea.
   *
   */
  void dfsSolution(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; ++i) {
      if (board[i][0] == 'O') {
        dfsSolutionHelper(board, i, 0, m, n, true);
      }
      if (board[i][n - 1] == 'O') {
        dfsSolutionHelper(board, i, n - 1, m, n, true);
      }
    }

    for (int j = 0; j < n; ++j) {
      if (board[0][j] == 'O') {
        dfsSolutionHelper(board, 0, j, m, n, true);
      }
      if (board[m - 1][j] == 'O') {
        dfsSolutionHelper(board, m - 1, j, m, n, true);
      }
    }

    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (board[i][j] == '0') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }

  /**
   * @brief We could union find to quickly solve this problem.
   * We could connect all the type to a dummy node which
   * connect all the boundaries whose values are 'O'.
   *
   */
  void unionFindSolution(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();
    DisjointSet set{m * n + 1};

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&
            board[i][j] == 'O') {
          // connect the boundary to the dummy node.
          set.connect(i * n + j, m * n);
        } else if (board[i][j] == 'O') {
          for (int k = 0; k < 4; ++k) {
            int nextI = i + dirs[k][0];
            int nextJ = j + dirs[k][1];

            if (iSValidForUnion(nextI, nextJ, m, n) &&
                board[nextI][nextJ] == 'O') {
              set.connect(i * n + j, nextI * n + nextJ);
            }
          }
        }
      }
    }

    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (board[i][j] == 'O' && !set.isConnect(i * n + j, m * n)) {
          board[i][j] = 'X';
        }
      }
    }
  }

  void solve(vector<vector<char>> &board) {
    dfsSolution(board);
    // unionFindSolution(board);
  }
};
// @lc code=end
