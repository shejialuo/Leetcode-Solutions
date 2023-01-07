/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

#include <queue>
using namespace std;

// @lc code=start
class RecentCounter {
private:
  queue<int> qu{};

public:
  RecentCounter() {}

  int ping(int t) {
    qu.push(t);
    int lastTime = t - 3000;
    while (!qu.empty() && qu.front() < lastTime) {
      qu.pop();
    }
    return qu.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
