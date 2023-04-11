/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    Node *ptr = root;
    while (ptr != nullptr) {
      Node *nextPtr = nullptr;
      Node *level = ptr;
      Node *pre = nullptr;

      while (level != nullptr) {
        if (level->left != nullptr) {

          // Set the nextPtr
          if (nextPtr == nullptr) {
            nextPtr = level->left;
          }

          if (pre != nullptr) {
            pre->next = level->left;
          }

          if (level->right != nullptr) {
            // case 1: the left child and the right child exists
            level->left->next = level->right;
            pre = level->right;
          } else {
            // case 2: the left child exists but the right child do not exists
            pre = level->left;
          }
        } else if (level->right != nullptr) {
          // case3 : the left child do not exists but the right child exists
          if (nextPtr == nullptr) {
            nextPtr = level->right;
          }

          if (pre != nullptr) {
            pre->next = level->right;
          }
          pre = level->right;
        }
        level = level->next;
      }

      ptr = nextPtr;
    }
    return root;
  }
};
// @lc code=end
