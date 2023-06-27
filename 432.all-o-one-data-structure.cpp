/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

#include <list>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class AllOne {
private:
  struct Info {
    string key;
    int count;

    Info(const string &k) : key{k}, count{1} {}
  };

  vector<list<Info>> infos{};
  unordered_map<string, list<Info>::iterator> keysToIterators{};

public:
  AllOne() { infos.resize(1); }

  void inc(string key) {
    auto iter = keysToIterators.find(key);
    if (iter == keysToIterators.end()) {
      infos[0].push_front(Info{key});
      keysToIterators[key] = infos[0].begin();
    } else {

      iter->second->count++;
      int count = iter->second->count;

      if (infos.size() < count) {
        infos.push_back(list<Info>{});
      }

      infos[count - 1].splice(infos[count - 1].begin(), infos[count - 2],
                              iter->second);
      keysToIterators[key] = infos[count - 1].begin();
    }
  }

  void dec(string key) {
    auto iter = keysToIterators.find(key);
    if (iter != keysToIterators.end()) {
      iter->second->count--;
      int count = iter->second->count;
      if (count == 0) {
        infos[0].erase(iter->second);
        keysToIterators.erase(key);
      } else {
        infos[count - 1].splice(infos[count - 1].begin(), infos[count],
                                iter->second);
        keysToIterators[key] = infos[count - 1].begin();
      }
    }
  }

  string getMaxKey() {
    int index = infos.size() - 1;
    while (index >= 0 && infos[index].empty()) {
      index--;
    }

    if (index < 0) {
      return "";
    }

    return infos[index].front().key;
  }

  string getMinKey() {
    int index = 0;
    while (index < infos.size() && infos[index].empty()) {
      index++;
    }

    if (index < infos.size()) {
      return infos[index].front().key;
    }

    return "";
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
