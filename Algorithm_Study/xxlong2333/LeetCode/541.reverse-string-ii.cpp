/*
 * @lc app=leetcode.cn id=541 lang=cpp
 * @lcpr version=30121
 *
 * [541] 反转字符串 II
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {

        string result;
        int n = s.size();

        for (int i = 0; i < n; i += (2 * k))
        {

            // 剩余字符 大于k，只翻转前k个字符
            if (i + k <= s.size())
                reverse(s.begin() + i, s.begin() + i + k);
            else // 剩余字符小于k个 全部翻转
                reverse(s.begin() + i, s.end());
        }

        return s;
        //  for (int i = 0; i < n; i += (2 * k)){
        //      // 翻转前k个字符
        //      cout << s[i] << endl;
        //  }
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */
