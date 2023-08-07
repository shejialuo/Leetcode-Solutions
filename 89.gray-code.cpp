/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] Gray Code
 */

#include <cmath>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  bool grayCodeHelper(vector<int> &ans, vector<int> &path, int cur, int n,
                      unordered_set<int> &visited) {
    if (path.size() == pow(2, n)) {
      int start = 1;
      while (start < pow(2, n)) {
        if (start == path.back()) {
          ans = path;
          return true;
        }
        start <<= 1;
      }
      return false;
    }

    for (int i = 0, pivot = 1; i < n; i++, pivot <<= 1) {
      int next = cur ^ pivot;
      if (!visited.count(next)) {
        visited.insert(next);
        path.push_back(next);
        if (grayCodeHelper(ans, path, next, n, visited)) {
          return true;
        }
        path.pop_back();
        visited.erase(next);
      }
    }
    return false;
  }

public:
  vector<int> grayCode(int n) {
    vector<int> ans{}, path{0};
    unordered_set<int> visited{0};
    grayCodeHelper(ans, path, 0, n, visited);
    return ans;
  }
};
// @lc code=end
