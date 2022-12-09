/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

/*
 * There are two corner case we should care about
 * When `x` is negative, we should just return false,
 * however, there are situation that `x` is 40000 or any
 * other, we should also return false
 */

// @lc code=start
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0))
      return false;
    int n = 0;
    while (x > n) {
      n = n * 10 + x % 10;
      x /= 10;
    }
    return (x == n) || (x == n / 10);
  }
};
// @lc code=end
