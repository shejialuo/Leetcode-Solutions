/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
/**
 * @brief Because we need to get O(1) for random, it is
 * normal for us to think use a vector to handle, however,
 * the problem it how to delete, we could do it easily, we
 * swap the index with the last value, and `pop_back`.
 *
 *
 */
class RandomizedSet {
private:
  vector<int> data{};
  unordered_map<int, int> table{};

public:
  RandomizedSet() {}

  bool insert(int val) {
    if (table.count(val)) {
      return false;
    }

    data.push_back(val);
    table[val] = data.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (!table.count(val)) {
      return false;
    }

    int index = table[val];
    int backValue = data.back();
    data[index] = backValue;
    table[backValue] = index;
    table.erase(val);
    data.pop_back();

    return true;
  }

  int getRandom() { return data[rand() % data.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
