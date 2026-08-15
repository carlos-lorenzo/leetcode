#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Easy
// Percent: 64.57687%



// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
// 
//  
// Example 1:
// 
// 
// Input: nums = [1,2,3,1]
// 
// Output: true
// 
// Explanation:
// 
// The element 1 occurs at the indices 0 and 3.
// 
// 
// Example 2:
// 
// 
// Input: nums = [1,2,3,4]
// 
// Output: false
// 
// Explanation:
// 
// All elements are distinct.
// 
// 
// Example 3:
// 
// 
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// 
// Output: true
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= nums.length <= 10⁵
// 	-10⁹ <= nums[i] <= 10⁹
// 
 

#include <cstddef>
#include <unordered_map>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int>seen{};
        for (size_t i=0; i<nums.size(); ++i) {
            if (seen.contains(nums[i])) {
                return true;
            }
            seen[nums[i]] = 1;
        }
        return false;
    }
};