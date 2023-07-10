/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU Cache
 */

#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
/**
 * @brief For this problem, it is very interesting, for myself,
 * we could think this problem is the same as the K-LRU. However,
 * for K-LRU, the code would only maintain the two linked list,
 * the one whose frequency is less than K, and the one is equal to K.
 *
 * For LFU, we could maintain a vector of list, 0 means count 1.
 * Thus, we could easily transfer the node
 *
 * count 1 : a -> b -> c.
 * count 2 : d -> e.
 * count 3 : ....
 *
 * when we use get `a`, we should make it to be
 * count 1 : b -> c
 * count 2 : a -> d -> e
 * count 3 : ....
 *
 * The official use a frequency table to handle this problem.
 * I don't think it's a good idea, why not just use a vector for
 * a better approach?
 */
class LFUCache {
private:
  class Info {
  private:
    int key;
    int value;
    int counter;

  public:
    Info() = delete;
    Info(int k, int v) : key{k}, value{v}, counter{1} {}

    int getKey() const { return key; }

    void setValue(int v) { value = v; }
    int getValue() const { return value; }

    int plusCounter() {
      counter++;
      return counter;
    }
  };

  vector<list<Info>> infos{};

  unordered_map<int, list<Info>::iterator> keysToIterators{};

  int size;
  int minFrequency{1};

public:
  LFUCache(int capacity) : size{capacity} { infos.resize(1); }

  int get(int key) {
    auto iter = keysToIterators.find(key);
    if (iter == keysToIterators.end()) {
      return -1;
    }

    int value = iter->second->getValue();
    int count = iter->second->plusCounter();
    if (infos.size() < count) {
      infos.emplace_back(list<Info>{});
    }

    infos[count - 1].splice(infos[count - 1].begin(), infos[count - 2],
                            iter->second);
    if (infos[count - 2].empty() && minFrequency == count - 1) {
      minFrequency++;
    }

    keysToIterators[key] = infos[count - 1].begin();

    return value;
  }

  void put(int key, int value) {
    auto iter = keysToIterators.find(key);
    if (iter == keysToIterators.end()) {
      if (keysToIterators.size() < size) {
        infos[0].push_front(Info{key, value});
        keysToIterators[key] = infos[0].begin();
      } else {

        keysToIterators.erase(infos[minFrequency - 1].back().getKey());
        infos[minFrequency - 1].pop_back();

        infos[0].push_front(Info{key, value});
        keysToIterators[key] = infos[0].begin();
      }
      minFrequency = 1;
    } else {
      iter->second->setValue(value);
      int count = iter->second->plusCounter();
      if (infos.size() < count) {
        infos.emplace_back(list<Info>{});
      }

      infos[count - 1].splice(infos[count - 1].begin(), infos[count - 2],
                              iter->second);

      keysToIterators[key] = infos[count - 1].begin();

      if (infos[count - 2].empty() && minFrequency == count - 1) {
        minFrequency++;
      }
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
