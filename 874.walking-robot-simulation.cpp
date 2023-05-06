/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

#include <array>
#include <functional>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  struct hashFunction {
    size_t operator()(const pair<int, int> &x) const {
      return x.first ^ x.second;
    }
  };

public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    int currentX = 0, currentY = 0;
    array<int, 4> speedX = {0, -1, 0, 1};
    array<int, 4> speedY = {1, 0, -1, 0};
    int direction = 0;
    int distance = 0;

    unordered_set<pair<int, int>, hashFunction> obstacleMaps;
    for (auto &&obstacle : obstacles) {
      obstacleMaps.insert({obstacle[0], obstacle[1]});
    }

    for (int i = 0; i < commands.size(); i++) {
      if (commands[i] == -2) {
        direction = (direction + 1) % 4;
      } else if (commands[i] == -1) {
        direction = (direction + 3) % 4;
      } else {
        int steps = commands[i];

        for (int step = 0; step < steps; step++) {
          currentX += speedX[direction];
          currentY += speedY[direction];
          if (obstacleMaps.count({currentX, currentY})) {
            currentX -= speedX[direction];
            currentY -= speedY[direction];
            break;
          }
        }

        distance = max(distance, currentX * currentX + currentY * currentY);
      }
    }

    return distance;
  }
};
// @lc code=end
