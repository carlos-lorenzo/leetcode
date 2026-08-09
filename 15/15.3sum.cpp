#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 39.578995%



// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// 
// Notice that the solution set must not contain duplicate triplets.
// 
//  
// Example 1:
// 
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// 
// 
// Example 2:
// 
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// 
// 
// Example 3:
// 
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
// 
// 
//  
// Constraints:
// 
// 
// 	3 <= nums.length <= 3000
// 	-10⁵ <= nums[i] <= 10⁵
// 
 

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
        vector<vector<int>> sol{};

        // i-1 is the fixed vaue
		for (size_t i=0; i<nums.size(); ++i) {
            if (nums[i] > 0) break;

            int left = i+1;
            int right = nums.size() - 1;
            
            if (i > 0){
                if (nums[i] == nums[i-1]) continue;
            }

            while (left < right) {
                auto current_sum = nums[i] + nums[left] + nums[right];
                
                if (current_sum == 0) {
                    sol.push_back({nums[i], nums[left], nums[right]});

                    
                    ++left;
                    --right;

                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    
                    
                } else if (current_sum > 0) {
                    --right;
                } else {
                    ++left;
                }

            }

        }
        return sol;
		
		
	}
};