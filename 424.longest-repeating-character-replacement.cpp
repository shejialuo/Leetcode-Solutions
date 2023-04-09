/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
  int characterReplacement(string s, int k) {
    int maxReplacementSubstringLength = 0;
    int maxCharacterFrequency = 0;

    unordered_map<char, int> table{};

    int windowStart = 0, windowEnd = 0;

    while (windowEnd < s.size()) {
      table[s[windowEnd]]++;
      maxCharacterFrequency = max(maxCharacterFrequency, table[s[windowEnd]]);
      windowEnd++;

      if (windowEnd - windowStart > k + maxCharacterFrequency) {
        // We should not alter maxCharacterFrequency, because it must be
        // incremented. This is the most difficult part
        table[s[windowStart++]]--;
      }

      maxReplacementSubstringLength =
          max(maxReplacementSubstringLength, windowEnd - windowStart);
    }

    return maxReplacementSubstringLength;
  }
};
// @lc code=end
