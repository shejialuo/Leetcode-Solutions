/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
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
private:
  void postorderHelper(Node* node, vector<int>& ans) {
    if(node != nullptr) {
      for(auto n : node->children) {
        postorderHelper(n , ans);
      }
      ans.push_back(node->val);
    }
  }
public:
  vector<int> postorder(Node* root) {
    vector<int> ans{};
    postorderHelper(root, ans);
    return ans;
  }
};
// @lc code=end

