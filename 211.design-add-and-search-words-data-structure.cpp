/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class WordDictionary {
private:
  class Node {
  private:
    char key;
    bool isEnd{false};
    unordered_map<char, unique_ptr<Node>> children{};

  public:
    Node(char key_) : key{key_} {}

    void setEnd() { isEnd = true; }

    bool isEnding() const { return isEnd; }

    unordered_map<char, unique_ptr<Node>> &getChildren() { return children; }

    unique_ptr<Node> *newChild(char c) {
      children[c] = std::move(make_unique<Node>(c));
      return &children[c];
    }

    unique_ptr<Node> *nextChild(char c) {
      if (children.count(c)) {
        return &children[c];
      }
      return nullptr;
    }
  };

  unique_ptr<Node> root;

  bool searchHelper(unique_ptr<Node> *ptr, int index, const string &word) {
    for (int i = index; i < word.size(); i++) {
      if (word[i] == '.') {
        for (auto &&childInfo : (*ptr)->getChildren()) {
          if (searchHelper(&childInfo.second, i + 1, word)) {
            return true;
          }
        }
        return false;
      } else {
        ptr = (*ptr)->nextChild(word[i]);
        if (ptr == nullptr) {
          return false;
        }
      }
    }
    return (*ptr)->isEnding();
  }

public:
  WordDictionary() { root = make_unique<Node>('a'); }

  void addWord(const string &word) {
    unique_ptr<Node> *ptr = &root;
    for (char c : word) {
      unique_ptr<Node> *child = (*ptr)->nextChild(c);
      if (child == nullptr) {
        ptr = (*ptr)->newChild(c);
      } else {
        ptr = child;
      }
    }
    (*ptr)->setEnd();
  }

  bool search(const string &word) { return searchHelper(&root, 0, word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
