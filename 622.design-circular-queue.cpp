/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

#include <vector>
using namespace std;

// @lc code=start
class MyCircularQueue {
private:
  vector<int> data{};
  int front = 0, rear = 0, count = 0;

public:
  MyCircularQueue(int k) { data.resize(k); }

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    data[front] = value;
    front = (front + 1) % data.size();
    count++;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    rear = (rear + 1) % data.size();
    count--;
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return data[rear];
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    if (front - 1 < 0) {
      return data[front - 1 + data.size()];
    }
    return data[front - 1];
  }

  bool isEmpty() { return count == 0; }

  bool isFull() { return count == data.size(); }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
