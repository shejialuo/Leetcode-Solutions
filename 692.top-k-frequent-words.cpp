/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  struct Comp {
    bool operator()(const pair<string, int> &p1, const pair<string, int> &p2) {
      return p1.second < p2.second ||
             (p1.second == p2.second && p1.first > p2.first);
    }
  };

public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> frequency{};
    for (const auto &word : words) {
      frequency[word]++;
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, Comp> heap{
        frequency.cbegin(), frequency.cend()};

    int i = 0;
    vector<string> ans{};
    while (i < k && !heap.empty()) {
      ans.push_back(heap.top().first);
      heap.pop();
      i++;
    }
    return ans;
  }
};
// @lc code=end
