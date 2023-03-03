/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

#include <queue>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief Change the view from right to the left.
   *
   */
  vector<int> replaceElements(vector<int> &arr) {
    vector<int> ans(arr.size(), 0);
    ans.back() = -1;

    priority_queue<int> heap{};
    heap.push(arr.back());

    for (int i = arr.size() - 2; i >= 0; i--) {
      ans[i] = heap.top();
      heap.push(arr[i]);
    }

    return ans;
  }
};
// @lc code=end
