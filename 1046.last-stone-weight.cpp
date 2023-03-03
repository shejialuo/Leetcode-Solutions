/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

#include <cmath>
#include <queue>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> heap{stones.begin(), stones.end()};

    while (heap.size() > 1) {
      int maxStoneWeight = heap.top();
      heap.pop();
      int secondMaxStoneWeight = heap.top();
      heap.pop();
      int remainWeight = maxStoneWeight - secondMaxStoneWeight;
      if (remainWeight != 0) {
        heap.push(remainWeight);
      }
    }
    if (heap.size() > 0) {
      return heap.top();
    } else {
      return 0;
    }
  }
};
// @lc code=end
