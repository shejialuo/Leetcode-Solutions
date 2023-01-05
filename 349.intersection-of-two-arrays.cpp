/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

/*
 * For this problem, it is easy to get the solution to use
 * hash table, however. We could also first sort the array
 * and use two pointers to get the answer. Yes, remember
 * when we merge two sorted subarray in the merge sort. The
 * idea is the same.
 */

// @lc code=start
class Solution {
private:
  vector<int> intersectionHash(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans{};
    unordered_set<int> hash{nums1.cbegin(), nums1.cend()};
    for (int num : nums2) {
      if (hash.count(num)) {
        ans.push_back(num);
        hash.erase(num);
      }
    }
    return ans;
  }
  vector<int> intersectionTwoPointer(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans{};
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j]) {
        if (ans.empty() || ans.back() != nums1[i]) {
          ans.push_back(nums1[i]);
        }
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

public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    // return intersectionHash(nums1, nums2);
    return intersectionTwoPointer(nums1, nums2);
  }
};
// @lc code=end
