/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans{};
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j]) {
        ans.push_back(nums1[i]);
        i++;
        j++;
      } else if (nums1[i] < nums2[j]) {
        i++;
      } else {
        j++;
      }
    }
    return ans;
  }
};
// @lc code=end
