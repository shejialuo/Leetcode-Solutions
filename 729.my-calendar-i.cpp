/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] My Calendar I
 */

#include <limits>
#include <set>
#include <utility>
using namespace std;

// @lc code=start
class MyCalendar {
private:
  struct Comp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const {
      return p1.first > p2.first;
    }
  };

  set<pair<int, int>, Comp> events{};

public:
  MyCalendar() {}

  bool book(int start, int end) {
    int previousStart = numeric_limits<int>::max();

    for (auto &&event : events) {
      if (event.first < start) {
        if (start >= event.second && end <= previousStart) {
          events.emplace(make_pair(start, end));
          return true;
        } else {
          return false;
        }
      }
      previousStart = event.first;
    }

    if (end <= previousStart) {
      events.emplace(make_pair(start, end));
      return true;
    }

    return false;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
