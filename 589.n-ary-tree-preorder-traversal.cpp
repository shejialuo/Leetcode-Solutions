/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

#include <vector>
#include <stack>
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
  void preorderHelper(Node* node, vector<int>& ans) {
    if(node != nullptr) {
      ans.push_back(node->val);
      for(auto n : node->children) {
        preorderHelper(n, ans);
      }
    }
  }
public:
  vector<int> preorder(Node* root) {
    vector<int> ans{};
    preorderHelper(root, ans);
    return ans;
  }
};
// @lc code=end

