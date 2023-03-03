/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ans{};
    priority_queue<int> heap{};
    unordered_map<int, int> table{};

    int start = 0, end = 0;

    while (end < nums.size()) {
      while (end - start + 1 <= k) {
        table[nums[end]]++;
        heap.push(nums[end]);
        end++;
      }

      while (table[heap.top()] == 0) {
        heap.pop();
      }
      ans.push_back(heap.top());
      table[nums[start]]--;
      start++;
    }

    return ans;
  }
};
// @lc code=end
