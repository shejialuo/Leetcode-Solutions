/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void numOfMinutesHelper(int id, vector<vector<int>> &informers,
                          vector<int> &informTime, int cur, int &maxTime) {
    cur += informTime[id];

    for (auto nextID : informers[id]) {
      numOfMinutesHelper(nextID, informers, informTime, cur, maxTime);
    }

    maxTime = max(maxTime, cur);
  }

public:
  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {

    vector<vector<int>> informers(manager.size());
    for (int i = 0; i < manager.size(); i++) {
      if (manager[i] != -1) {
        informers[manager[i]].push_back(i);
      }
    }

    int ans = 0;
    numOfMinutesHelper(headID, informers, informTime, 0, ans);
    return ans;
  }
};
// @lc code=end
