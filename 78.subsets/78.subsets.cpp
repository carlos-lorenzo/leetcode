#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 82.6399%



// Given an integer array nums of unique elements, return all possible subsets (the power set).
// 
// The solution set must not contain duplicate subsets. Return the solution in any order.
// 
//  
// Example 1:
// 
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
// 
// Example 2:
// 
// Input: nums = [0]
// Output: [[],[0]]
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= nums.length <= 10
// 	-10 <= nums[i] <= 10
// 	All the numbers of nums are unique.
// 
 

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        backtrack(0, {}, nums, sol);
        return sol;
    }
    void backtrack(size_t start, vector<int> current, vector<int>& choices, vector<vector<int>> &sol) {
        sol.push_back(current);
        for (size_t i=start; i<choices.size(); ++i) {
            current.push_back(choices[i]);
            backtrack(i+1, current, choices, sol);
            current.pop_back();
        }
    }
};
