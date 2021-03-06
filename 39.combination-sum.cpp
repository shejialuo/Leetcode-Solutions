/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <vector>
using namespace std;

/*
  * This is a combination problem. So we need to use an index
  * to make sure that the answer is unqiue. When we have searched
  * all the possible of one value, we should drop it (this is what
  * index has done).
  *
  * For the other part, it is common. Just search all the
  * possible branches.
*/

// @lc code=start
class Solution {
private:
  vector<vector<int>> ans{};
  vector<int> combination{};
  void combinationSumHelper(vector<int>& candiates, int index, int sum, int target) {
    if(sum > target) {
      return;
    } else if(sum == target) {
      ans.push_back(combination);
    } else {
      for(int i = index; i < candiates.size(); ++i) {
        combination.push_back(candiates[i]);
        combinationSumHelper(candiates, i, sum + candiates[i], target);
        combination.pop_back();
      }
    }
  }
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    combinationSumHelper(candidates, 0 ,0, target);
    return ans;
  }
};
// @lc code=end

