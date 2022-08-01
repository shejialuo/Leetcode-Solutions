/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hash{};
    vector<vector<string>> ans{};
    for(string& s: strs) {
      string t {s};
      sort(t.begin(), t.end());
      hash[t].push_back(s);
    }
    for(auto h : hash) {
      ans.push_back(h.second);
    }
    return ans;
  }
};
// @lc code=end

