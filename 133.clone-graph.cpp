/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] Clone Graph
 */

#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
  void cloneGraphHelper(Node *node, Node *cur,
                        unordered_map<Node *, Node *> &visited) {
    visited[cur] = node;
    for (auto &&neighbor : cur->neighbors) {
      if (visited.count(neighbor)) {
        node->neighbors.push_back(visited[neighbor]);
      } else {
        Node *newNode = new Node{neighbor->val};
        node->neighbors.push_back(newNode);
        cloneGraphHelper(newNode, neighbor, visited);
      }
    }
  }

public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr) {
      return node;
    }
    unordered_map<Node *, Node *> visited{};
    Node *ans = new Node{node->val};
    visited[node] = ans;
    cloneGraphHelper(ans, node, visited);
    return ans;
  }
};
// @lc code=end
