#include <algorithm>
#include <array>
#include <print>
#include <unordered_map>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 61.72924%



// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// 
// The solution set must not contain duplicate subsets. Return the solution in any order.
// 
//  
// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:
// Input: nums = [0]
// Output: [[],[0]]
// 
//  
// Constraints:
// 
// 
// 	1 <= nums.length <= 10
// 	-10 <= nums[i] <= 10
// 
 

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums); 

        vector<vector<int>> sol;
        vector<int> curr {};

        backtrack(curr, sol, nums, 0);

        return sol;
    }

    void backtrack(vector<int> &curr, vector<vector<int>> &sol, vector<int>& nums, size_t start) {
        sol.push_back(curr); // Can't emplace back/move as curr will be used again
        
        for (auto i=start; i<nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(curr, sol, nums, i+1);
            curr.pop_back();
        }

    }

};
