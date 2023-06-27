/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 *
 * [1670] Design Front Middle Back Queue
 */

#include <iostream>
#include <iterator>
#include <list>
using namespace std;

// @lc code=start
/**
 * @brief This problem, we should maintain an iterator to the
 * middle, it is really difficult to do so. May two deque is
 * a better approach
 *
 */
class FrontMiddleBackQueue {
private:
  list<int> data{};
  list<int>::iterator middle{};

public:
  FrontMiddleBackQueue() {}

  void pushFront(int val) {
    data.push_front(val);

    if (data.size() == 1) {
      // When the length is 1, middle always points to `data.begin()`.
      middle = data.begin();
    } else if (data.size() % 2 == 0) {
      // 1 2 3, middle points to 2, when a new element e comes
      // e 1 2 3, middle should point to 2.
      advance(middle, -1);
    }
  }

  void pushMiddle(int val) {
    if (data.empty()) {
      // When it is empty, we should not use middle at all.
      data.push_front(val);
      middle = data.begin();
    } else if (data.size() % 2 == 0) {
      middle = data.insert(next(middle), val);
    } else {
      middle = data.insert(middle, val);
    }
  }

  void pushBack(int val) {
    data.push_back(val);
    if (data.size() == 1) {
      middle = data.begin();
    } else if (data.size() % 2 != 0) {
      advance(middle, 1);
    }
  }

  int popFront() {
    if (data.empty()) {
      return -1;
    }
    int val = data.front();
    data.pop_front();

    if (data.size() == 1) {
      middle = data.begin();
    } else if (!data.empty() && data.size() % 2 != 0) {
      advance(middle, 1);
    }
    return val;
  }

  int popMiddle() {
    if (data.empty()) {
      return -1;
    }

    int val = *middle;
    middle = data.erase(middle);
    if (!data.empty() && data.size() % 2 == 0) {
      advance(middle, -1);
    }
    return val;
  }

  int popBack() {
    if (data.empty()) {
      return -1;
    }

    int val = data.back();
    data.pop_back();

    if (!data.empty() && data.size() % 2 == 0) {
      advance(middle, -1);
    }
    return val;
  }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end
