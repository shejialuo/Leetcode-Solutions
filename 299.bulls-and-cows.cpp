/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
  string getHint(string secret, string guess) {
    unordered_map<char, int> table{};
    unordered_set<int> visited{};

    int bulls = 0;

    for (int i = 0; i < secret.size(); i++) {
      if (secret[i] == guess[i]) {
        visited.insert(i);
        bulls++;
      } else {
        table[secret[i]]++;
      }
    }

    int cows = 0;
    for (int i = 0; i < secret.size(); i++) {
      if (!visited.count(i) && table[guess[i]] != 0) {
        cows++;
        table[guess[i]]--;
      }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};
// @lc code=end
