/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

#include <list>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  enum class State {
    NotVisited,
    Visiting,
    Visited,
  };

  bool hasLoop = false;

  void findOrderHelper(int current, list<int> &courses, vector<State> &states,
                       vector<vector<int>> &graph) {
    states[current] = State::Visiting;

    for (auto next : graph[current]) {
      if (states[next] == State::Visiting) {
        hasLoop = true;
        break;
      }

      if (states[next] == State::NotVisited) {
        findOrderHelper(next, courses, states, graph);
      }
    }
    states[current] = State::Visited;
    courses.push_front(current);
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<State> states(numCourses, State::NotVisited);
    list<int> courses{};

    vector<vector<int>> graph(numCourses, vector<int>{});

    for (auto &&prerequisite : prerequisites) {
      graph[prerequisite[1]].push_back(prerequisite[0]);
    }

    for (int i = 0; i < numCourses; i++) {
      if (states[i] == State::NotVisited) {
        findOrderHelper(i, courses, states, graph);
      }
    }

    if (hasLoop) {
      return {};
    }
    return vector<int>{courses.cbegin(), courses.cend()};
  }
};
// @lc code=end
