/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include <queue>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  struct Comp {
    bool operator()(const vector<int> &v1, const vector<int> &v2) {
      return v1[0] * v1[0] + v1[1] * v1[1] > v2[0] * v2[0] + v2[1] * v2[1];
    }
  };

  vector<vector<int>> kClosestHeap(vector<vector<int>> &points, int k) {
    priority_queue<vector<int>, vector<vector<int>>, Comp> heap{points.cbegin(),
                                                                points.cend()};

    vector<vector<int>> ans{};
    int i = 0;
    while (i < k && !heap.empty()) {
      ans.push_back(heap.top());
      heap.pop();
      i++;
    }
    return ans;
  }

public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    return kClosestHeap(points, k);
  }
};
// @lc code=end
