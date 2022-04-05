/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] Remove Element
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    /*
      * It is easy to think just use `erase` method
      * to do this, however, we should use O(n) method
      * We could maintain two pointers.
    */
    int pointerEqual = 0;
    int pointerNotEqual = 0;
    while(pointerNotEqual < nums.size()) {
      if(nums[pointerNotEqual] != val) {
        if(pointerEqual != pointerNotEqual) {
          swap(nums[pointerEqual], nums[pointerNotEqual]);
        }
        pointerEqual++;
        pointerNotEqual++;
      } else {
        pointerNotEqual++;
      }
    }
    return pointerEqual;
  }
};
// @lc code=end

