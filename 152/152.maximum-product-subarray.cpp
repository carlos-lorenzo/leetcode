#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 36.786%



// Given an integer array nums, find a subarray that has the largest product, and return the product.
// 
// The test cases are generated so that the answer will fit in a 32-bit integer.
// 
// Note that the product of an array with a single element is the value of that element.
// 
//  
// Example 1:
// 
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// 
// 
// Example 2:
// 
// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= nums.length <= 2 * 10⁴
// 	-10 <= nums[i] <= 10
// 	The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
// 
 

#include <iostream>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        auto local_min = 1;
        auto local_max = 1;
        auto global_max = nums[0];
        
        for (const int num : nums) {
            local_min = std::min(1, local_min);
            local_max = std::max(1, local_max);
            local_max *= num; // might become negative
            local_min *= num; // might become postive    
                   
            auto local_best = std::max(local_max, local_min);
            auto local_worst = std::min(local_max, local_min);
            local_max = local_best;
            local_min = local_worst;

            global_max = std::max(global_max, local_best);
            
        }
        return global_max;
        
    }
};