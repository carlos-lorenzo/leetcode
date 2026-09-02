#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

#include <string>
#include <string_view>
#include <unordered_map>

// Category: algorithms
// Level: Medium
// Percent: 66.55698%



// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// 
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// 
//  
// Example 1:
// 
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
// 
// Example 2:
// 
// Input: digits = "2"
// Output: ["a","b","c"]
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= digits.length <= 4
// 	digits[i] is a digit in the range ['2', '9'].
// 
 
const unordered_map<char, vector<char>> chars {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}
};

const array<string_view, 10> CHAR_MAP = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

class Solution {
public:
    
    
    vector<string> letterCombinations(string digits) {
       vector<string> sol{};
       size_t req_vecs = 1;
       for (const auto d : digits)  {
            req_vecs *= CHAR_MAP[d - '0'].size();
       }
       sol.reserve(req_vecs);
       string current;
       current.reserve(digits.size());
       backtrack(0, digits, current, sol);
       return sol;

        
    }

    void backtrack(size_t i, string &digits, string &current, vector<string> &sol) noexcept {
        if (i == digits.size()) {
            sol.push_back(current);
            return;
        }
    
        for (const auto curr_char : CHAR_MAP[digits[i] - '0']) {
            current.push_back(curr_char);
            backtrack(i+1, digits, current, sol);
            current.pop_back();
        }
    }
};