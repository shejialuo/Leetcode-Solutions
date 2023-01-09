/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

#include <type_traits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * We should think about this question in another perspective.
   * The problem is that we should do it at O(n+m) time. We can
   * easily do this reversely. Because we can easily get the max
   * num.
   */
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int maxPointer = m + n - 1;
    int i = m - 1, j = n - 1;
    while (i >= 0 || j >= 0) {
      if (i < 0) {
        while (j >= 0) {
          nums1[maxPointer--] = nums2[j--];
        }
      } else if (j < 0) {
        while (i >= 0) {
          nums1[maxPointer--] = nums1[i--];
        }
      } else if (nums1[i] > nums2[j]) {
        nums1[maxPointer--] = nums1[i--];
      } else {
        nums1[maxPointer--] = nums2[j--];
      }
    }
  }
};
// @lc code=end
