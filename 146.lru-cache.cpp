/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU Cache
 */

#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

// @lc code=start
class LRUCache {
private:
  int size;
  list<pair<int, int>> items{};
  unordered_map<int, typename list<pair<int, int>>::iterator> keyToIterators{};

public:
  LRUCache(int capacity) : size(capacity) {}

  int get(int key) {
    auto pos = keyToIterators.find(key);
    if (pos == keyToIterators.end()) {
      return -1;
    }

    int value = pos->second->second;
    items.erase(pos->second);
    items.push_front(make_pair(key, value));
    keyToIterators[key] = items.begin();

    return value;
  }

  void put(int key, int value) {
    auto pos = keyToIterators.find(key);
    if (pos == keyToIterators.end()) {
      items.push_front(make_pair(key, value));
      keyToIterators[key] = items.begin();
      if (items.size() > size) {
        keyToIterators.erase(items.back().first);
        items.pop_back();
      }
    } else {
      items.erase(pos->second);
      items.push_front(std::make_pair(key, value));
      keyToIterators[key] = items.begin();
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
