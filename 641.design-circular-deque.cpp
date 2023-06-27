/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

#include <tuple>
#include <vector>
using namespace std;

// @lc code=start
class MyCircularDeque {
private:
  vector<int> data{};
  int front = 0, rear = 0, count = 0;

public:
  MyCircularDeque(int k) { data.resize(k); }

  bool insertFront(int value) {
    if (isFull()) {
      return false;
    }

    data[front] = value;
    front = (front - 1 + data.size()) % data.size();
    count++;

    return true;
  }

  bool insertLast(int value) {
    if (isFull()) {
      return false;
    }

    rear = (rear + 1) % data.size();
    data[rear] = value;
    count++;

    return true;
  }

  bool deleteFront() {
    if (isEmpty()) {
      return false;
    }

    front = (front + 1) % data.size();
    count--;

    return true;
  }

  bool deleteLast() {
    if (isEmpty()) {
      return false;
    }
    rear = (rear - 1 + data.size()) % data.size();
    count--;
    return true;
  }

  int getFront() {
    if (isEmpty()) {
      return -1;
    }
    return data[(front + 1) % data.size()];
  }

  int getRear() {
    if (isEmpty()) {
      return -1;
    }
    return data[rear];
  }

  bool isEmpty() { return count == 0; }

  bool isFull() { return count == data.size(); }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end
