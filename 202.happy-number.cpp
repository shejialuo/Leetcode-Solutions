/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] Happy Number
 */

#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> hash{};
    while(hash.count(n) == 0) {
      hash.insert(n);
      int temp = 0;
      while(n) {
        temp += (n % 10) * (n % 10);
        n /= 10;
      }
      n = temp;
      if(n == 1) return true;
    }
    return false;
  }
};
// @lc code=end

