/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <vector>
#include <unordered_map>
using namespace std;

/*
  * For this question, the answer is easy. When we iterate
  * the array, if we find the corresponding `target-nums[i]`
  * doesn't in the `unordered_map`, we add it to. If we find,
  * we are successful.
*/

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash {};
    for(int i = 0; i < nums.size(); ++i) {
      int index = hash[target - nums[i]];
      if(index != 0) {
        return vector<int>{i, index - 1};
      }
      hash[nums[i]] = i + 1;
    }
    return vector<int>{};
  }
};
// @lc code=end
