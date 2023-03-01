/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int i = 0, j = people.size() - 1;
    int boat = 0;
    while (i <= j) {
      if (people[i] + people[j] > limit) {
        j--;
      } else {
        i++;
        j--;
      }
      boat++;
    }
    return boat;
  }
};
// @lc code=end
