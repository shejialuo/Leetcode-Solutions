/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

#include <functional>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  bool findItineraryHelper(int n,
                           unordered_map<string, map<string, int>> &table,
                           vector<string> &ans) {

    if (ans.size() == n + 1) {
      return true;
    }

    for (auto &&to : table[ans.back()]) {
      if (to.second > 0) {
        to.second--;
        ans.push_back(to.first);
        if (findItineraryHelper(n, table, ans)) {
          return true;
        }
        to.second++;
        ans.pop_back();
      }
    }

    return false;
  }

public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {

    unordered_map<string, map<string, int>> table{};
    for (auto &&ticket : tickets) {
      std::string &from = ticket[0];
      std::string &to = ticket[1];
      table[from][to]++;
    }

    vector<string> ans{};
    ans.push_back("JFK");

    findItineraryHelper(tickets.size(), table, ans);

    return ans;
  }
};
// @lc code=end
