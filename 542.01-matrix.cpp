/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

#include <queue>
#include <utility>
#include <vector>
using namespace std;

// Todo: efficiency is bad

// @lc code=start
class Solution {
private:
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  bool isValid(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
  }

  int updateMatrixHelper(vector<vector<int>> &mat, int i, int j) {
    queue<pair<int, int>> qu{};
    qu.push({i, j});

    int num = -1;

    while (!qu.empty()) {
      num++;
      int size = qu.size();
      for (int i = 0; i < size; ++i) {
        auto &&front = qu.front();

        if (mat[front.first][front.second] == 0) {
          return num;
        }

        for (int k = 0; k < 4; ++k) {
          int nextI = front.first + dirs[k][0];
          int nextJ = front.second + dirs[k][1];

          if (isValid(nextI, nextJ, mat.size(), mat[0].size())) {
            qu.push({nextI, nextJ});
          }
        }
        qu.pop();
      }
    }

    return num;
  }

public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> ans{};
    ans.resize(n);

    for (auto &&a : ans) {
      a.resize(m);
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 0) {
          ans[i][j] = 0;
        } else if (mat[i][j] == 1) {
          ans[i][j] = updateMatrixHelper(mat, i, j);
        }
      }
    }

    return ans;
  }
};
// @lc code=end
