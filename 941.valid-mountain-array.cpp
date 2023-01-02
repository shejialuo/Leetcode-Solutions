/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  bool validMountainArray(vector<int> &arr) {
    if (arr.size() < 3) {
      return false;
    }
    int i = 0;
    while (i < arr.size() - 1 && arr[i] < arr[i + 1]) {
      i++;
    }
    if (i == arr.size() - 1 || i == 0) {
      return false;
    }
    while (i < arr.size() - 1 && arr[i] > arr[i + 1]) {
      i++;
    }
    if (i != arr.size() - 1) {
      return false;
    }
    return true;
  }
};
// @lc code=end
