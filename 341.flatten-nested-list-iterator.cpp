/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

#include <memory>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
  // Whenever we encounter a new list, we should add
  // it to the stack, because we need to record the
  // current list and its iterator, so we should use
  // the following data structure.
  stack<pair<const vector<NestedInteger> *, int>> st;

public:
  NestedIterator(const vector<NestedInteger> &nestedList) {
    st.push(make_pair(&nestedList, 0));
  }

  // For next, we make sure that it is an actual integer
  int next() {
    auto [cur, iter] = st.top();
    st.top().second++;
    return (*cur)[iter].getInteger();
  }

  bool hasNext() {
    while (!st.empty()) {
      auto &&[cur, iter] = st.top();
      while (iter < cur->size()) {
        // When the list is empty, we should jump over it, this is
        // very important
        if (!(*cur)[iter].isInteger() && (*cur)[iter].getList().empty()) {
          iter++;
          continue;
        }

        // If the current is not an integer, we should dive into it
        // and recursively called hasNext().
        if (!(*cur)[iter].isInteger()) {
          st.push(make_pair(&(*cur)[iter].getList(), 0));
          // jump over it
          iter++;
          return hasNext();
        }

        return true;
      }
      st.pop();
    }
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
