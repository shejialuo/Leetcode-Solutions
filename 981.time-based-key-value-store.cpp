/*
 * @lc app=leetcode.cn id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class TimeMap {
private:
  struct Data {
    string value;
    int timestamp;

    Data(const string &value_, int timestamp_)
        : value{value_}, timestamp{timestamp_} {}
  };

  unordered_map<string, vector<Data>> table{};

public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    if (table.count(key) == 0) {
      table[key] = vector<Data>{};
    }
    table[key].push_back(Data{value, timestamp});
  }

  string get(string key, int timestamp) {
    auto &&values = table[key];

    // Use binary search to solve this problem.

    int start = 0, end = values.size();
    int index = -1;

    while (start < end) {
      int mid = (start + end) / 2;
      if (values[mid].timestamp == timestamp) {
        return values[mid].value;
      } else if (values[mid].timestamp > timestamp) {
        end = mid;
      } else {
        index = mid;
        start = mid + 1;
      }
    }

    if (index != -1) {
      return values[index].value;
    }

    return "";
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
