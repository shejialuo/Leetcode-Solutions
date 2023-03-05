/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

#include <stack>
using namespace std;

// @lc code=start
class MyQueue {
private:
  stack<int> st{};
  stack<int> qu{};

public:
  MyQueue() {}

  void push(int x) { st.push(x); }

  int pop() {
    int value = peek();
    qu.pop();
    return value;
  }

  int peek() {
    if (!qu.empty()) {
      return qu.top();
    } else {
      while (!st.empty()) {
        qu.push(st.top());
        st.pop();
      }
      return qu.top();
    }
  }

  bool empty() { return st.empty() && qu.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
