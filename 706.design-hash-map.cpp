/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] Design HashMap
 */

#include <algorithm>
#include <list>
#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class MyHashMap {
private:
  vector<list<pair<int, int>>> data{};
  static constexpr int base{769};
  static int hash(int key) { return key % base; }

public:
  MyHashMap() { data.resize(base); }

  void put(int key, int value) {
    int h = hash(key);
    auto it = find_if(
        data[h].begin(), data[h].end(),
        [key = key](const pair<int, int> &p) { return p.first == key; });
    if (it != data[h].end()) {
      it->second = value;
    } else {
      data[h].push_back(make_pair(key, value));
    }
  }

  int get(int key) {
    int h = hash(key);
    auto it = find_if(
        data[h].cbegin(), data[h].cend(),
        [key = key](const pair<int, int> &p) { return p.first == key; });
    if (it != data[h].cend()) {
      return it->second;
    }
    return -1;
  }

  void remove(int key) {
    int h = hash(key);
    auto it = find_if(
        data[h].begin(), data[h].end(),
        [key = key](const pair<int, int> &p) { return p.first == key; });
    if (it != data[h].end()) {

      data[h].erase(it);
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
