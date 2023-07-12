/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

#include <queue>
#include <vector>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> children;
  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> ans{};
    queue<Node *> qu;
    if (root != nullptr) {
      qu.push(root);
    }
    while (!qu.empty()) {
      int length = qu.size();
      vector<int> layer{};
      for (int i = 0; i < length; ++i) {
        Node *node = qu.front();
        layer.push_back(node->val);
        for (Node *child : node->children) {
          qu.push(child);
        }
        qu.pop();
      }
      ans.push_back(std::move(layer));
    }
    return ans;
  }
};
// @lc code=end
