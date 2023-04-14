/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */

#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
  int listLength(ListNode *head) {
    int length = 0;
    while (head != nullptr) {
      length++;
      head = head->next;
    }
    return length;
  }

public:
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    vector<ListNode *> ans{};

    int length = listLength(head);

    int more = length % k;
    int size = length / k;

    ListNode *pre = nullptr;

    for (int i = 0; i < k; ++i) {
      ans.push_back(head);
      int j = 0;
      while (head != nullptr && j < size) {
        pre = head;
        head = head->next;
        j++;
      }
      if (more != 0) {
        pre = head;
        head = head->next;
        more--;
      }
      if (pre != nullptr) {
        pre->next = nullptr;
      }
    }

    return ans;
  }
};
// @lc code=end
