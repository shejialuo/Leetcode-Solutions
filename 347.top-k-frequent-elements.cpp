/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> table{};
    for (auto &&num : nums) {
      table[num]++;
    }
    priority_queue<pair<int, int>> heap{};
    for (auto &&p : table) {
      heap.push(make_pair(p.second, p.first));
    }

    vector<int> ans{};

    int i = 0;
    while (!heap.empty() && i < k) {
      ans.push_back(heap.top().second);
      i++;
      heap.pop();
    }

    return ans;
  }
};
// @lc code=end
