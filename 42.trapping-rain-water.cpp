/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  int trapBruteForce(vector<int> &height) {
    int totalWater = 0;
    for (int i = 0; i < height.size(); i++) {
      if (i == 0 || i == height.size() - 1) {
        continue;
      }

      int leftSuccessor = height[i];
      int rightSuccessor = height[i];

      for (int j = 0; j < i; j++) {
        leftSuccessor = max(leftSuccessor, height[j]);
      }

      for (int j = i + 1; j < height.size(); j++) {
        rightSuccessor = max(rightSuccessor, height[j]);
      }

      if (leftSuccessor != height[i] && rightSuccessor != height[i]) {
        totalWater += min(leftSuccessor, rightSuccessor) - height[i];
      }
    }
    return totalWater;
  }

  int trapMemoized(vector<int> &height) {
    vector<int> leftSuccessors(height.size(), 0);
    vector<int> rightSuccessors(height.size(), 0);

    int leftMax = height[0];
    for (int i = 1; i < height.size(); i++) {
      leftMax = max(leftMax, height[i]);
      leftSuccessors[i] = leftMax;
    }

    int rightMax = height.back();
    for (int i = height.size() - 2; i >= 1; i--) {
      rightMax = max(rightMax, height[i]);
      rightSuccessors[i] = rightMax;
    }

    int totalWater = 0;
    for (int i = 0; i < height.size(); i++) {
      if (i == 0 || i == height.size() - 1) {
        continue;
      }
      totalWater += min(rightSuccessors[i], leftSuccessors[i]) - height[i];
    }
    return totalWater;
  }

  int trapMonolithicStack(vector<int> &height) {
    stack<int> st{};

    int totalWater = 0;
    for (int i = 0; i < height.size(); i++) {

      while (!st.empty() && height[i] > height[st.top()]) {
        int mid = st.top();
        st.pop();
        if (!st.empty()) {
          int h = min(height[i], height[st.top()]) - height[mid];
          int w = i - st.top() - 1;
          totalWater += h * w;
        }
      }
      st.push(i);
    }
    return totalWater;
  }

public:
  int trap(vector<int> &height) {
    // Brute Force
    // return trapBruteForce(height);

    // Memoized way
    // return trapMemoized(height);

    return trapMonolithicStack(height);
  }
};
// @lc code=end
