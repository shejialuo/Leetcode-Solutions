/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
private:
  struct Node {
    int val;
    Node *next;
    Node *pre;
    Node() : val{0}, pre{nullptr}, next{nullptr} {}
  };
  Node *head;
  Node *tail;
  int size{};

  void insertNode(Node *ptr, int val) {
    size++;
    Node *node = new Node();
    node->val = val;
    node->next = ptr->next;
    node->pre = ptr;
    node->next->pre = node;
    ptr->next = node;
  }

public:
  MyLinkedList() {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->pre = head;
  }

  int get(int index) {
    if (index < size) {
      Node *ptr = head->next;
      for (int i = 0; i < index; ++i) {
        ptr = ptr->next;
      }
      return ptr->val;
    }
    return -1;
  }

  void addAtHead(int val) { insertNode(head, val); }

  void addAtTail(int val) { insertNode(tail->pre, val); }

  void addAtIndex(int index, int val) {
    if (index <= size) {
      Node *ptr = head;
      for (int i = 0; i < index; ++i) {
        ptr = ptr->next;
      }
      insertNode(ptr, val);
    }
  }

  void deleteAtIndex(int index) {
    if (index < size) {
      Node *ptr = head;
      for (int i = 0; i < index; ++i) {
        ptr = ptr->next;
      }
      Node *node = ptr->next;
      ptr->next = node->next;
      ptr->next->pre = ptr;
      delete node;
      size--;
    }
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
