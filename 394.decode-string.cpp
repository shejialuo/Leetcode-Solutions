/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] Decode String
 */

#include <cassert>
#include <cctype>
#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
  /**
   * The question is a parse, it is not difficult, if you have tried
   * to write a simple interpreter. The recursion should start when
   * we encounter a new '[', it is a new same problem. When we encounter
   * a new ']', we should return the current string to the upper problem.
   *
   * @param s the string reference it self
   * @param index current index
   * @return string the decoded string
   */
  string decodeStringHelper(const string &s, size_t &index) {
    string decode{};
    size_t accumulate = 0;
    while (index < s.size()) {
      char c = s[index];
      index++;
      if (c == '[') {
        // solve the subproblem
        string result = decodeStringHelper(s, index);
        for (int j = 0; j < accumulate; ++j) {
          decode.append(result);
        }
        // reset `accumulate` to be zero.
        accumulate = 0;
      } else if (c == ']') {
        return decode;
      } else if (isdigit(c)) {
        accumulate = (c - '0') + (accumulate * 10);
      } else {
        decode.push_back(c);
      }
    }
    return decode;
  }

public:
  string decodeString(string s) {
    size_t start = 0;
    return decodeStringHelper(s, start);
  }
};
// @lc code=end

class Test {
private:
  Solution s{};

public:
  void testSuite1() {
    string case1 = "2[ac]";
    assert(s.decodeString(case1) == "acac");

    string case2 = "2[ab1[a]]";
    assert(s.decodeString(case2) == "abaaba");

    string case3 = "1[abcdeaaa]";
    assert(s.decodeString(case3) == "abcdeaaa");
  }

  void testSuite2() {
    string case1 = "2[2[2[a]]]";
    assert(s.decodeString(case1) == "aaaaaaaa");

    string case2 = "2[2[ab]adsa2[cd]]";
    assert(s.decodeString(case2) == "ababadsacdcdababadsacdcd");

    string case3 = "1[2[a]3[b]4[d]5[c]]";
    assert(s.decodeString(case3) == "aabbbddddccccc");
  }

  void operator()() {
    testSuite1();
    testSuite2();
  }
};

int main() {
  Test test{};
  test();
}
