/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

#include <queue>
using namespace std;

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

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
  /**
   * @brief We should use the internal data structure.
   *
   */
  Node *connectHighEfficiency(Node *root) {
    if (root == nullptr) {
      return root;
    }

    Node *ptr = root;
    while (ptr->left != nullptr) {
      Node *head = ptr;
      while (head != nullptr) {
        // Situation 1: if they are connected by the same parent.
        head->left->next = head->right;

        // Situation 2: if they are connected by the different parent.
        // one parent is head, next parent is head->next
        if (head->next != nullptr) {
          head->right->next = head->next->left;
        }

        head = head->next;
      }
      ptr = ptr->left;
    }
    return root;
  }

  /**
   * @brief It is easy to get a solution to use
   * BFS, however, this is bad.
   */
  Node *connectBFS(Node *root) {
    queue<Node *> qu{};

    if (root != nullptr) {
      qu.push(root);
    }

    while (!qu.empty()) {
      int size = qu.size();
      for (int i = 0; i < size; ++i) {
        Node *node = qu.front();
        qu.pop();

        if (i + 1 < size) {
          node->next = qu.front();
        }

        if (node->left != nullptr) {
          qu.push(node->left);
        }
        if (node->right != nullptr) {
          qu.push(node->right);
        }
      }
    }

    return root;
  }

public:
  Node *connect(Node *root) { return connectHighEfficiency(root); }
};
// @lc code=end
