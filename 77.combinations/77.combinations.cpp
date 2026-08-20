#include <cstddef>
#include <vector>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 74.935234%



// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
// 
// You may return the answer in any order.
// 
//  
// Example 1:
// 
// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
// 
// 
// Example 2:
// 
// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= n <= 20
// 	1 <= k <= n
// 
 

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> sol{};
        vector<int> current{};
        backtrack(1, n, static_cast<std::size_t>(k), current, sol);
        return sol;
    }

    void backtrack(int start, int n, size_t k, vector<int> current, vector<vector<int>> &sol) {
        if (current.size() == k) {
            sol.push_back(current);
            return;
        }
        for (int i=start; i<=n; ++i) {
            current.push_back(i);
            backtrack(i+1, n, k, current, sol);
            current.pop_back();
        }
    }
};
