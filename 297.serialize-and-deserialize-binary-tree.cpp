/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

#include <cstdlib>
#include <list>
#include <sstream>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string>
using namespace std;

class Codec {
private:
  void serializeHelper(TreeNode *node, string &str) {
    if (node == nullptr) {
      str += "null,";
    } else {
      str += to_string(node->val) + ",";
      serializeHelper(node->left, str);
      serializeHelper(node->right, str);
    }
  }

  TreeNode *deserializeHelper(list<string> &tokens) {
    if (tokens.front() == "null") {
      tokens.pop_front();
      return nullptr;
    }

    TreeNode *node = new TreeNode{stoi(tokens.front())};
    tokens.pop_front();
    node->left = deserializeHelper(tokens);
    node->right = deserializeHelper(tokens);
    return node;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string str;
    serializeHelper(root, str);
    return str;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    stringstream ss{data};

    list<string> tokens{};

    std::string token{};

    while (getline(ss, token, ',')) {
      tokens.push_back(token);
    }

    return deserializeHelper(tokens);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
