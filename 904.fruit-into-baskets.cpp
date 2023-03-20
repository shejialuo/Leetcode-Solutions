/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  /**
   * @brief It is easy for us to think about the solutions to use
   * brute force, we could start from a tree of index i, and traverse the tree
   * from i + 1 to the end of the tree. However, we have calculated so
   * many extra things. O(N^2).
   *
   */
  int totalFruitBruteForce(vector<int> &fruits) {
    int maxFruit = 0;
    int fruit = 0;
    for (int i = 0; i < fruits.size(); ++i) {
      unordered_set<int> types{};
      fruit = 0;
      for (int j = i; j < fruits.size(); ++j) {
        if (types.count(fruits[j])) {
          fruit++;
        } else if (types.size() == 2) {
          break;
        } else {
          types.insert(fruits[j]);
          fruit++;
        }
      }
      maxFruit = max(fruit, maxFruit);
    }
    return maxFruit;
  }

  int totalFruitSlidingWindow(vector<int> &fruits) {
    unordered_map<int, int> types{};
    int windowStart = 0, windowEnd = 0;

    int maxFruit = 0;

    while (windowEnd < fruits.size()) {
      types[fruits[windowEnd]]++;

      while (types.size() > 2) {
        auto it = types.find(fruits[windowStart]);
        it->second--;
        if (it->second == 0) {
          types.erase(it);
        }
        ++windowStart;
      }

      maxFruit = max(maxFruit, windowEnd - windowStart + 1);

      windowEnd++;
    }

    return maxFruit;
  }

public:
  int totalFruit(vector<int> &fruits) {
    return totalFruitSlidingWindow(fruits);
  }
};
// @lc code=end
