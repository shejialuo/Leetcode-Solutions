/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

#include <queue>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <vector>
using namespace std;

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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *aux = new ListNode(-1);
    ListNode *p = aux;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        p->next = list1;
        list1 = list1->next;
      } else {
        p->next = list2;
        list2 = list2->next;
      }
      p = p->next;
    }
    p->next = list1 == nullptr ? list2 : list1;

    ListNode *ans = aux->next;
    delete aux;
    return ans;
  }

  // The most easiest way: brute force to solve this problem
  // Merge it one by one
  ListNode *mergeKListsBruteForce(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }

    ListNode *ans = lists[0];

    for (int i = 1; i < lists.size(); i++) {
      ans = mergeTwoLists(ans, lists[i]);
    }

    return ans;
  }

  ListNode *mergeKListsDivideAndConquer(vector<ListNode *> &lists, int start,
                                        int end) {
    if (start < end) {
      int mid = (start + end) / 2;
      ListNode *left = mergeKListsDivideAndConquer(lists, start, mid);
      ListNode *right = mergeKListsDivideAndConquer(lists, mid + 1, end);
      return mergeTwoLists(left, right);
    } else if (start == end) {
      return lists[start];
    } else {
      return nullptr;
    }
  }

  ListNode *heapMergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }

    struct comp {
      bool operator()(ListNode *l1, ListNode *l2) { return l1->val > l2->val; }
    };

    priority_queue<ListNode *, vector<ListNode *>, comp> heap{};

    for (auto &&node : lists) {
      if (node != nullptr) {
        heap.push(node);
      }
    }
    ListNode *aux = new ListNode{};
    ListNode *ptr = aux;

    while (!heap.empty()) {
      ListNode *node = heap.top();
      heap.pop();
      ptr->next = node;
      ptr = ptr->next;
      if (node->next != nullptr) {
        heap.push(node->next);
      }
    }

    ListNode *ans = aux->next;
    delete aux;
    return ans;
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // Brute Force
    // return mergeKListsBruteForce(lists);

    // Divide and conquer
    // return mergeKListsDivideAndConquer(lists, 0, lists.size() - 1);

    // Heap
    return heapMergeKLists(lists);
  }
};
// @lc code=end
