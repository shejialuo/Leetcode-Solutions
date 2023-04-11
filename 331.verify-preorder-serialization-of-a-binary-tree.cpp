/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

#include <cctype>
#include <stack>
#include <string>
#include <utility>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief The idea is to use stack, however, I use
   * an intuitive way to solve this problem
   *
   */
  bool isValidSerialization(string preorder) {

    stack<pair<int, int>> st{};
    // push a dummy node here, it is si
    st.push(make_pair(-1, 1));

    for (int i = 0; i < preorder.size(); i++) {
      // If we form a tree, and the iteration do not stop
      // we should return false here
      if (st.empty()) {
        return false;
      }

      if (isdigit(preorder[i])) {
        int num = 0;
        while (i < preorder.size() && isdigit(preorder[i])) {
          num = num * 10 + preorder[i] - '0';
          i++;
        }
        i--;
        st.push(make_pair(num, 0));
      } else if (preorder[i] == '#') {
        st.top().second++;

        // If we have constructed the left tree and right tree
        // we should recursively do this.
        while (!st.empty() && st.top().second == 2) {
          st.pop();
          if (!st.empty()) {
            st.top().second++;
          }
        }
      }
    }

    return st.empty();
  }
};
// @lc code=end
