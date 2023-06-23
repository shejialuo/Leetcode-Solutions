/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] Design HashSet
 */

#include <algorithm>
#include <list>
#include <vector>
using namespace std;

// @lc code=start
class MyHashSet {
private:
  vector<list<int>> data{};
  static const int base{769};
  static int hash(int key) { return key % base; }

public:
  MyHashSet() { data.resize(base); }

  void add(int key) {
    int h = hash(key);
    auto it = find(data[h].cbegin(), data[h].cend(), key);
    if (it != data[h].cend()) {
      return;
    }

    data[h].push_back(key);
  }

  void remove(int key) {
    int h = hash(key);
    auto it = find(data[h].begin(), data[h].end(), key);
    if (it != data[h].end()) {
      data[h].erase(it);
    }
  }

  bool contains(int key) {
    int h = hash(key);
    auto it = find(data[h].cbegin(), data[h].cend(), key);
    return it != data[h].cend();
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
