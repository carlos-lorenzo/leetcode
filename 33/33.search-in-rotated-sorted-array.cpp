// Category: algorithms
// Level: Medium
// Percent: 45.352985%



// There is an integer array nums sorted in ascending order (with distinct values).
// 
// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
// 
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// 
// You must write an algorithm with O(log n) runtime complexity.
// 
//  
// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:
// Input: nums = [1], target = 0
// Output: -1
// 
//  
// Constraints:
// 
// 
// 	1 <= nums.length <= 5000
// 	-10⁴ <= nums[i] <= 10⁴
// 	All values of nums are unique.
// 	nums is an ascending array that is possibly rotated.
// 	-10⁴ <= target <= 10⁴
// 
 

#include <cstddef>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#endif

class Solution {
public:
   
    int find_k(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int first_true_index = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= nums.back()) {
                first_true_index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return first_true_index;
    }

    int binary_serach(int left, int right, std::vector<int>& nums, int target) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        if (left > right) return -1;
        if (nums[mid] > target) return binary_serach(left, mid - 1, nums, target);
        if (nums[mid] < target) return binary_serach(mid+1, right, nums, target);
        return -1;
    }
    

    int search(std::vector<int>& nums, int target) {
        
        auto k = find_k(nums);
        int left, right;
        if (target < nums[0] || k == 0) {
            // target has to be in "wrapped" section
            left = k;
            right = nums.size() - 1;
        } else {
            left = 0;
            right = k - 1;
        }

      

        return binary_serach(left, right, nums, target);
        
    }
};
