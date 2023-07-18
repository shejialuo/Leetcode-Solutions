/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief We should maintain a monolithic stack
   *
   */
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> ans(temperatures.size(), 0);
    stack<int> st{};

    for (int i = 0; i < temperatures.size(); i++) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        ans[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }

    return ans;
  }
};
// @lc code=end
