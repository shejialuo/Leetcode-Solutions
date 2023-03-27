/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> table{};
    for (int i = 0; i < nums1.size(); i++) {
      table[nums1[i]] = i;
    }

    stack<int> st{};
    vector<int> ans(nums1.size(), -1);

    for (auto &&num : nums2) {
      while (!st.empty() && num > st.top()) {
        ans[table[st.top()]] = num;
        st.pop();
      }
      if (table.count(num)) {
        st.push(num);
      }
    }

    return ans;
  }
};
// @lc code=end
