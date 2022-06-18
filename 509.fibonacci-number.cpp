/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
  int fib(int n) {
    if(n == 0 || n == 1) return n;
    int f1 = 1, f2 = 0;
    for(int i = 2; i <=n; ++i) {
      int temp = f1;
      f1 = f1 + f2;
      f2 = temp;
    }
    return f1;
  }
};
// @lc code=end

