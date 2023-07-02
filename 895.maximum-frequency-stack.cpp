/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class FreqStack {
private:
  struct Data {
    int val;
    int index;
    int frequency;

    Data() = default;
    Data(int v, int i, int f) : val{v}, index{i}, frequency{f} {}

    bool operator()(const Data &d1, const Data &d2) {
      return d1.frequency < d2.frequency ||
             (d1.frequency == d2.frequency && d1.index < d2.index);
    }
  };

  int index{0};

  unordered_map<int, int> frequencyInfo{};

  priority_queue<Data, vector<Data>, Data> heap{};

public:
  FreqStack() {}

  void push(int val) {
    frequencyInfo[val]++;
    heap.push(Data{val, index++, frequencyInfo[val]});
  }

  int pop() {
    int result = heap.top().val;
    frequencyInfo[heap.top().val]--;
    heap.pop();
    return result;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end
