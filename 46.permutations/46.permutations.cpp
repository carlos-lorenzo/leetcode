#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 82.19925%



// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// 
//  
// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:
// Input: nums = [1]
// Output: [[1]]
// 
//  
// Constraints:
// 
// 
// 	1 <= nums.length <= 6
// 	-10 <= nums[i] <= 10
// 	All the integers of nums are unique.
// 

#include <iostream>
#include <vector>
#include <ranges>
#include <print>
 

class Solution {
public:
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> sol{};
    size_t req_size = 1;
    for (size_t i = 1; i <= nums.size(); ++i) req_size *= i;
    sol.reserve(req_size);
    vector<int> current{};
    current.reserve(nums.size());

    backtrack(nums, current, sol);

    return sol;
}

    void backtrack(vector<int> &choices, vector<int> &current, vector<vector<int>> &sol) {
        auto remaining = choices.size();

        if (remaining == 0) {
            sol.emplace_back(current); // Current no longer needed
            return;
        }
        
        
        for (auto i=0uz; i<choices.size(); ++i) {
            auto current_choice = choices[i];
            
            current.push_back(current_choice);
            std::swap(choices[i], choices.back());
            choices.pop_back();

            backtrack(choices, current, sol);
            
            current.pop_back();
            choices.push_back(current_choice);
            std::swap(choices[i], choices.back());

        }
    }
};
