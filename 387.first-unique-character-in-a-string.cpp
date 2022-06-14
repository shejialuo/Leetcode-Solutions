/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int firstUniqChar(string s) {
    int ans = -1;
    vector<int> hash(26, 0);
    for(char c : s) hash[c - 'a']++;
    for(int i = 0; i < s.length(); i++){
			if(hash[s[i] - 'a'] == 1) return i;
		}
		return -1;
  }
};
// @lc code=end

