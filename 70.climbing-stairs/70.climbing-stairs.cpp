#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Easy
// Percent: 54.244797%



// You are climbing a staircase. It takes n steps to reach the top.
// 
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// 
//  
// Example 1:
// 
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// 
// 
// Example 2:
// 
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= n <= 45
// 
 

class Solution {
public:
    int climbStairs(int n) {
       // Since the number of steps for 1 step left is 1 and for 2 is 2. And for three 2 + 1 = 3. This is fibonacci
        const double root_five = std::sqrt(5);
        const double phi = (1 + root_five) / 2;
        const double psi = (1 - root_five) / 2;

        return round((std::pow(phi, n+1) - std::pow(psi, n+1)) / root_five);
    }
};
