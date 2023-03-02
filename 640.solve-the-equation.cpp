/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] Solve the Equation
 */

#include <cctype>
#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
  void helper(bool flag, int &num, int sum) { flag ? num += sum : num -= sum; }

public:
  string solveEquation(string equation) {
    int index = 0;
    int coefficient = 0;
    int num = 0;
    bool isLeft = true;
    bool isSum = true;
    while (index < equation.size()) {
      if (equation[index] == '+' || equation[index] == '-') {
        equation[index] == '+' ? isSum = isLeft : isSum = !isLeft;
      } else if (equation[index] == 'x') {
        helper(isSum, coefficient, 1);
      } else if (equation[index] == '=') {
        // We should change state here
        isSum = false;
        isLeft = false;
      } else {
        int sum = 0;
        while (index < equation.size() && isdigit(equation[index])) {
          sum = sum * 10 + equation[index] - '0';
          index++;
        }
        if (index < equation.size() && equation[index] == 'x') {
          helper(isSum, coefficient, sum);
        } else {
          helper(isSum, num, sum);
          continue;
        }
      }
      index++;
    }

    if (num == 0 && coefficient == 0) {
      return "Infinite solutions";
    } else if (coefficient == 0) {
      return "No solution";
    } else {
      int x = -num / coefficient;
      return "x=" + to_string(x);
    }
  }
};
// @lc code=end
