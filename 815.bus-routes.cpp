/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] Bus Routes
 */

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  struct Level {
    unordered_set<int> buses{};
    unordered_set<Level *> children{};
  };

public:
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {

    if (source == target) {
      return 0;
    }

    unordered_map<int, unordered_set<int>> routesTable{};

    vector<Level> levels(routes.size(), Level{});
    unordered_set<Level *> visited{};
    queue<Level *> qu{};
    unordered_set<Level *> ends{};

    for (int i = 0; i < routes.size(); i++) {
      levels[i].buses.insert(routes[i].cbegin(), routes[i].cend());
      if (levels[i].buses.count(source)) {
        visited.insert(&levels[i]);
        qu.push(&levels[i]);
      }
      if (levels[i].buses.count(target)) {
        ends.insert(&levels[i]);
      }
    }

    for (int i = 0; i < routes.size(); i++) {
      for (int j = i + 1; j < routes.size(); j++) {
        for (auto station : routes[j]) {
          if (levels[i].buses.count(station)) {
            levels[i].children.insert(&levels[j]);
            levels[j].children.insert(&levels[i]);
            break;
          }
        }
      }
    }

    int step = 1;
    while (!qu.empty()) {
      int size = qu.size();
      for (int i = 0; i < size; i++) {
        Level *level = qu.front();
        if (ends.count(level)) {
          return step;
        }
        for (auto &&child : level->children) {
          if (!visited.count(child)) {
            qu.push(child);
            visited.insert(child);
          }
        }
        qu.pop();
      }
      step++;
    }

    return -1;
  }
};
// @lc code=end