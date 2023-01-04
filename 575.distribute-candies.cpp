/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * It is an easy problem. Just abstract the model
   *
   * @param candyType
   * @return int
   */
  int distributeCandies(vector<int> &candyType) {
    unordered_set<int> types{};
    for (auto &&type : candyType) {
      types.insert(type);
    }
    return types.size() <= candyType.size() / 2 ? types.size()
                                                : candyType.size() / 2;
  }
};
// @lc code=end
