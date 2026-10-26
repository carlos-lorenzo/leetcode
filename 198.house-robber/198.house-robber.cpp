#include <array>
#include <cstddef>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 53.44665%



// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// 
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// 
//  
// Example 1:
// 
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// 
// 
// Example 2:
// 
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
// 
// 
// Input: nums = [2,1,9,1,1,8]
//  
// Constraints:
// 
// 
// 	1 <= nums.length <= 100
// 	0 <= nums[i] <= 400
// 
 


class Solution {
public:
    int rob(vector<int>& nums) {
        array<int, 100> cache{};
        cache.fill(-1);
        return solve(nums, 0, cache);
    }

private:
    int solve(const vector<int>& nums, size_t i, array<int, 100>& cache) {
        if (i >= nums.size()) {
            return 0;
        }

        if (cache[i] != -1) {
            return cache[i];
        }

        int rob_current = nums[i] + solve(nums, i + 2, cache);
        int skip_current = solve(nums, i + 1, cache);

        return cache[i] = max(rob_current, skip_current);
    }
};

