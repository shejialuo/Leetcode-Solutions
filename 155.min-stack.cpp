/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <limits>

// @lc code=start
class MinStack {
private:
  int size;
  int *item;
  int capacity;
  int minNumber;

  bool isEmpty() {
    return size == 0;
  }

  bool isFull() {
    return size == capacity;
  }

  void resize() {
    int *newItem = new int[capacity * 2];
    for(int i = 0; i < capacity; ++i) {
      newItem[i] = item[i];
    }
    capacity = capacity * 2;
    delete[] item;
    item = newItem;
  }

  void findMin() {
    int min = std::numeric_limits<int>::max();
    for(int i = 0; i < size; ++i) {
      if(item[i] < min) {
        min = item[i];
      }
    }
    minNumber = min;
  }

public:
  MinStack() {
    capacity = 100;
    item = new int[capacity];
    size = 0;
    minNumber = std::numeric_limits<int>::max();
  }

  void push(int val) {
    if(isFull()) {
      resize();
    }
    item[size] = val;
    size++;
    if(val < minNumber) {
      minNumber = val;
    }
  }

  void pop() {
    if(!isEmpty()) {
      int topNum = top();
      size--;
      if(topNum == minNumber) {
        findMin();
      }
    }
  }

  int top() {
    if(isEmpty()) {
      return -1;
    }
    return item[size - 1];
  }

  int getMin() {
    if (isEmpty()) {
      return -1;
    }
    return minNumber;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

