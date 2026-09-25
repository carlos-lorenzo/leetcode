#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 41.307007%



// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 
// 
// 	0 <= a, b, c, d < n
// 	a, b, c, and d are distinct.
// 	nums[a] + nums[b] + nums[c] + nums[d] == target
// 
// 
// You may return the answer in any order.
// 
//  
// Example 1:
// 
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 
// 
// Example 2:
// 
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= nums.length <= 200
// 	-10⁹ <= nums[i] <= 10⁹
// 	-10⁹ <= target <= 10⁹
// 
 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        if (nums.size() < 4) return {};
        std::ranges::sort(nums);
        vector<vector<int>> solution{};
        for (size_t i=0; i<nums.size() - 3; ++i) {
            if ((target > 0 && nums[i] > target)) break;
            
            if (i > 0 && nums[i] == nums[i-1]) continue;
                

            for (size_t j=i+1; j<nums.size() - 2; ++j) {
                if ((target > 0 && static_cast<long>(nums[j]) + static_cast<long>(nums[i])  > static_cast<long>(target))) break;

                if (j > i+1 && nums[j] == nums[j-1]) continue;

                auto left = j + 1;
                auto right = nums.size() - 1;
                while (left < right) {
                    long current_sum = static_cast<long>(nums[i]) + static_cast<long>(nums[j])  + static_cast<long>(nums[left]) + static_cast<long>(nums[right]) ;
                    if (current_sum == target) {
                        solution.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;

                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }

                    } else if (current_sum > target) {
                        --right;
                    } else {
                        ++left;
                    }
                    
                }
            }
        }
        return solution;
    }
};
