/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] String Compression
 */

#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int compress(vector<char> &chars) {
    int writePointer = 0;
    int index = 0;
    while (index < chars.size()) {
      int same = 1;
      char current = chars[index];

      int nextIndex = index + 1;
      for (; nextIndex < chars.size() && chars[nextIndex] == current;
           nextIndex++) {
        same++;
      }

      chars[writePointer++] = current;

      if (same != 1) {
        stack<char> st{};
        while (same != 0) {
          st.push(same % 10 + '0');
          same /= 10;
        }

        while (!st.empty()) {
          chars[writePointer++] = st.top();
          st.pop();
        }
      }

      index = nextIndex;
    }
    return writePointer;
  }
};
// @lc code=end
