/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
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
  class CMP {
  public:
    bool operator()(const pair<char, int> &p1, const pair<char, int> &p2) {
      return p1.second < p2.second;
    }
  };

public:
  string frequencySort(string s) {
    unordered_map<char, int> frequency{};
    for (int i = 0; i < s.size(); ++i) {
      frequency[s[i]]++;
    }

    priority_queue<pair<char, int>, std::vector<pair<char, int>>, CMP> heap{
        frequency.begin(), frequency.end()};

    string ans(s.size(), ' ');

    int index = 0;
    while (!heap.empty()) {
      auto &&value = heap.top();

      for (int i = 0; i < value.second; ++i) {
        ans[index++] = value.first;
      }

      heap.pop();
    }

    return ans;
  }
};
// @lc code=end
