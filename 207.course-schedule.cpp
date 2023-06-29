/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] Course Schedule
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

  void canFinishHelper(int current, list<int> &courses, vector<State> &states,
                       vector<vector<int>> &graph) {
    states[current] = State::Visiting;

    for (auto next : graph[current]) {
      if (states[next] == State::Visiting) {
        hasLoop = true;
        break;
      }

      if (states[next] == State::NotVisited) {
        canFinishHelper(next, courses, states, graph);
      }
    }
    states[current] = State::Visited;
    courses.push_front(current);
  }

public:
  /**
   * @brief It's important to understand when we can finish all the courses,
   * it may seem we could just use typology sort. However, there may be a
   * cycle in the graph. This is the most important question.
   *
   * How to know whether a graph has a cycle. For any node, there are
   * three state:
   *
   * 1. not visited.
   * 2. visiting.
   * 3. visited.
   *
   * If we find a node which is current visiting, we have a cycle.
   */
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<State> states(numCourses, State::NotVisited);
    list<int> courses{};

    vector<vector<int>> graph(numCourses, vector<int>{});

    for (auto &&prerequisite : prerequisites) {
      graph[prerequisite[1]].push_back(prerequisite[0]);
    }

    for (int i = 0; i < numCourses; i++) {
      if (states[i] == State::NotVisited) {
        canFinishHelper(i, courses, states, graph);
      }
    }

    return !hasLoop && courses.size() == numCourses;
  }
};
// @lc code=end
