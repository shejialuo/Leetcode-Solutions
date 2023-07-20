/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
  Node *flattenHelper(Node *node) {
    Node *ptr = node, *pre = nullptr;

    while (ptr != nullptr) {
      if (ptr->child != nullptr) {
        Node *next = ptr->next;
        ptr->next = ptr->child;
        ptr->child->prev = ptr;

        Node *end = flattenHelper(ptr->child);
        ptr->child = nullptr;

        end->next = next;
        if (next != nullptr) {
          next->prev = end;
        }
        pre = end;
        ptr = next;
      } else {
        pre = ptr;
        ptr = ptr->next;
      }
    }
    return pre;
  }

public:
  Node *flatten(Node *head) {
    flattenHelper(head);
    return head;
  }
};
// @lc code=end
