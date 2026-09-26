#include <cstddef>
#include <string>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 54.751503%



// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
// 
// P   A   H   N
// A P L S I I G
// Y   I   R
// 
// 
// And then read line by line: "PAHNAPLSIIGYIR"
// 
// Write the code that will take a string and make this conversion given a number of rows:
// 
// string convert(string s, int numRows);
// 
// 
//  
// Example 1:
// 
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// 
// 
// Example 2:
// 
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// 
// 
// Example 3:
// 
// Input: s = "A", numRows = 1
// Output: "A"
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= s.length <= 1000
// 	s consists of English letters (lower-case and upper-case), ',' and '.'.
// 	1 <= numRows <= 1000
// 
 
class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1) return s;
            string converted{};
            converted.resize(s.size());
            size_t i = 0;
            for (int current_row=0; current_row<numRows; ++current_row) {
                size_t global_index = current_row;
                bool next_upward = false;
                while (global_index < s.size()) {
                    // std::cout << s[global_index] << ", ";
                    converted[i] = s[global_index];
                    size_t delta_index = 0;
                    if (!next_upward) delta_index = to_next_downward(current_row, numRows);
                    else delta_index = to_next_upward(current_row);
                    next_upward = !next_upward;
                    if (delta_index > 0) {
                        ++i;
                        global_index += delta_index;
                    }
                }
            }
    
    
            return converted;
        }
        size_t to_next_downward(int current_row, int total_rows) {
            return (total_rows - current_row - 1) * 2;
        }
    
        size_t to_next_upward(int current_row) {
            return current_row * 2;
        }
    };
