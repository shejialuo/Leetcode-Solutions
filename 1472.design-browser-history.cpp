/*
 * @lc app=leetcode.cn id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

#include <array>
#include <string>
using namespace std;

// @lc code=start
class BrowserHistory {
private:
  array<string, 1000> histories{};
  int ptr{0};
  int length{0};

public:
  BrowserHistory(string homepage) {
    histories[ptr++] = homepage;
    length = ptr;
  }

  void visit(string url) {
    histories[ptr++] = url;
    length = ptr;
  }

  string back(int steps) {
    ptr = ptr - steps >= 1 ? ptr - steps : 1;
    return histories[ptr - 1];
  }

  string forward(int steps) {
    ptr = ptr + steps <= length ? ptr + steps : length;
    return histories[ptr - 1];
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end
