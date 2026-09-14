#include <cstddef>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 68.98942%



// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
// 
//  
// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]
// 
//  
// Constraints:
// 
// 
// 	1 <= temperatures.length <= 10⁵
// 	30 <= temperatures[i] <= 100
// 
 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> pending{};
        vector<int> solution(temperatures.size(), 0);

        for (size_t i=0; i<temperatures.size(); ++i) {

            while (!pending.empty()) {
                auto top_index = pending.top();
                if (temperatures[top_index] >= temperatures[i]) break;
                solution[top_index] = i - top_index;
                pending.pop(); 
            }

            pending.push(i);
        }

        return solution;
    }
};
