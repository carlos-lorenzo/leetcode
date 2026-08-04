// Category: algorithms
// Level: Hard
// Percent: 49.047234%



// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// 
// Return the max sliding window.
// 
//  
// Example 1:
// 
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// 
// 
// Example 2:
// 
// Input: nums = [1], k = 1
// Output: [1]
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= nums.length <= 10⁵
// 	-10⁴ <= nums[i] <= 10⁴
// 	1 <= k <= nums.length
// 
 

#include <deque>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#endif

class Solution {
public:
    

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> solution{};

        // Stores indices such that front always has the largest index
        // Indices pruned from the front if expired ie i - stored_index > k
        // Pop elements from the back until the leftover elements are greater than the new number as these can no longer be a maximum
        deque<int> indices{};
       
        for (int i=0; i<static_cast<int>(nums.size()); ++i) {
            // Prune indices
            while (!indices.empty() && i - indices.front() >= k) indices.pop_front();
            while (!indices.empty() && nums[indices.back()] <= nums[i]) indices.pop_back();
            
            indices.push_back(i);
            if (i > k - 2) solution.push_back(nums[indices.front()]);
        }
        
        return solution;
    }
    
};
