/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

#include <vector>
using namespace std;

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
  int maxDepth(Node* root) {
    if(root == nullptr) return 0;
    int max = 0;
    for(Node* node : root->children) {
      int depth = maxDepth(node);
      if(depth > max) {
        max = depth;
      }
    }
    return 1 + max;
  }
};
// @lc code=end

