#include <string>
#include <vector>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 78.99068%



// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// 
//  
// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:
// Input: n = 1
// Output: ["()"]
// 
//  
// Constraints:
// 
// 
// 	1 <= n <= 8
// 
 
class Solution {



public:
vector<string> generateParenthesis(int n) noexcept{
        constexpr std::array<int, 9> CATALAN_NUMBERS = {0, 1, 2, 5, 14, 42, 132, 429, 1430};
        vector<string> sol{};
        if (n <= 0) return sol;
        sol.reserve(CATALAN_NUMBERS[n]);
        string current = "(";
        current.reserve(2*n);


        backtrack(n-1, n, current, sol);
        return sol;
    }

    void backtrack(int open_remaining, int closed_remaining, string &current, vector<string> &sol) {
        

        if (open_remaining == 0 && closed_remaining == 0) {
            sol.push_back(current);
            return;
        }
        if (open_remaining > 0 && closed_remaining > 0) {
            current.push_back('(');
            
            backtrack(open_remaining-1, closed_remaining, current, sol);
            current.pop_back();
        }
        if (closed_remaining > 0 && open_remaining < closed_remaining) {
            current.push_back(')');
    
            backtrack(open_remaining, closed_remaining-1, current, sol);
            current.pop_back();
        }
    }
};
