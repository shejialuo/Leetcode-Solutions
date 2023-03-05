/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

#include <queue>
using namespace std;

// @lc code=start
class MyStack {
private:
  queue<int> qu{};

public:
  MyStack() {}

  void push(int x) {
    qu.push(x);
    for (int i = 1; i < qu.size(); ++i) {
      qu.push(qu.front());
      qu.pop();
    }
  }

  int pop() {
    int value = top();
    qu.pop();
    return value;
  }

  int top() { return qu.front(); }

  bool empty() { return qu.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
