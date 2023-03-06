/*
 * @lc app=leetcode.cn id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

#include <cctype>
#include <map>
#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
  map<string, int> countOfAtomsHelper(int &start, string &formula) {
    map<string, int> table{};
    while (start < formula.size()) {
      if (formula[start] == '(') {
        start++;
        auto result = countOfAtomsHelper(start, formula);
        for (auto &&[atom, num] : result) {
          table[atom] += num;
        }
      } else if (formula[start] == ')') {
        int copy = 0;
        start++;
        while (start < formula.size() && isdigit(formula[start])) {
          copy = (formula[start] - '0') + copy * 10;
          start++;
        }

        if (copy == 0) {
          copy = 1;
        }

        for (auto &&[atom, num] : table) {
          table[atom] *= copy;
        }

        return table;

      } else if (start < formula.size() && isupper(formula[start])) {
        int position = start;
        start++;
        while (start < formula.size() && islower(formula[start])) {
          start++;
        }
        string sub = formula.substr(position, start - position);

        int num = 0;
        while (start < formula.size() && isdigit(formula[start])) {
          num = (formula[start] - '0') + num * 10;
          start++;
        }

        if (num == 0) {
          num = 1;
        }

        table[sub] += num;
      }
    }
    return table;
  }

public:
  string countOfAtoms(string formula) {
    int start = 0;
    map<string, int> table = countOfAtomsHelper(start, formula);
    string ans;
    for (auto &&[atom, num] : table) {
      ans += atom;
      if (num != 1) {
        ans += to_string(num);
      }
    }
    return ans;
  }
};
// @lc code=end
