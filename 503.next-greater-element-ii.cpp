/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> st{};

    int length = 2 * nums.size() - 1;

    for (int i = 0; i < length; i++) {
      while (!st.empty() &&
             nums[st.top() % nums.size()] < nums[i % nums.size()]) {
        if (st.top() < nums.size()) {
          ans[st.top() % nums.size()] = nums[i % nums.size()];
        }
        st.pop();
      }
      st.push(i);
    }

    return ans;
  }
};
// @lc code=end
