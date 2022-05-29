/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if(head == nullptr) {
      return nullptr;
    }
    unordered_map<Node*, Node*> isCreated;
    Node* result = new Node(head->val);
    Node* ptr = result;
    isCreated.insert({head, result});
    while(head != nullptr) {
      if(head->next == nullptr) {
        ptr->next = nullptr;
      } else if(isCreated.count(head->next)) {
        ptr->next = isCreated[head->next];
      } else {
        Node* n = new Node(head->next->val);
        isCreated.insert({head->next, n});
        ptr->next = n;
      }
      if(head->random == nullptr) {
        ptr->random = nullptr;
      } else if(isCreated.count(head->random)) {
        ptr->random = isCreated[head->random];
      } else{
        Node* r = new Node(head->random->val);
        isCreated.insert({head->random, r});
        ptr->random = r;
      }
      ptr = ptr->next;
      head = head->next;
    }
    return result;
  }
};
// @lc code=end

