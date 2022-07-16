/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
  * This question can be used by four ways, and this is really
  * a good problem because of its extend.
  *
  * 1. In-place hash
  * 2. Floyd circle detection
  * 3. Sort
*/

// @lc code=start
class Solution {
public:

  /*
    * Since the numbers are [1:N], so we use the
    * array indices for s visited state of each
    * number, only the duplicate will be visit

    * In-place Hash
  */
  int indexSolution(vector<int>& nums) {
    for(int i = 0; i < nums.size(); ++i) {
      int index = abs(nums[i]) - 1;
      nums[index] *= -1;
      if(nums[index] > 0) {
        return abs(nums[i]);
      }
    }
    return -1;
  }

  /*
    * Floyd circle detection
    * Assume each nums value as an address like in linked list node
    * address. Then since there is one number with duplicates, that
    * means there are multiple of the same address, so it is a
    * cycle just like in linked list.
  */
  int folydCircleSolution(vector<int>& nums) {
    int hare = nums[0], tortoise = nums[0];
    do {
      hare = nums[nums[hare]];
      tortoise = nums[tortoise];
    }while(hare != tortoise);
    tortoise = nums[0];
    while(hare != tortoise) {
      hare = nums[hare];
      tortoise = nums[tortoise];
    }
    return hare;
  }

  /*
    * Sort
    * For sorting, the idea is simple, we just find
    * nums[i] == nums[i] + 1
  */
  int sortSolution(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int duplicate = 0;
    for(int i = 0; i < nums.size() - 1; ++i) {
      if(nums[i] == nums[i + 1]) {
        duplicate = nums[i];
        break;
      }
    }
    return duplicate;
  }

  int findDuplicate(vector<int>& nums) {
    return indexSolution(nums);
  }
};
// @lc code=end

