#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Easy
// Percent: 44.61946%



// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// 
// An input string is valid if:
// 
// 
// 	Open brackets must be closed by the same type of brackets.
// 	Open brackets must be closed in the correct order.
// 	Every close bracket has a corresponding open bracket of the same type.
// 
// 
//  
// Example 1:
// 
// 
// Input: s = "()"
// 
// Output: true
// 
// 
// Example 2:
// 
// 
// Input: s = "()[]{}"
// 
// Output: true
// 
// 
// Example 3:
// 
// 
// Input: s = "(]"
// 
// Output: false
// 
// 
// Example 4:
// 
// 
// Input: s = "([])"
// 
// Output: true
// 
// 
// Example 5:
// 
// 
// Input: s = "([)]"
// 
// Output: false
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= s.length <= 10⁴
// 	s consists of parentheses only '()[]{}'.
// 
 
class Solution {
    public:
        bool isValid(string s) noexcept {
            stack<char, vector<char>> st;
    
            for (char c : s) {
                if (c == '(' || c == '[' || c == '{') {
                    st.push(c);
                } else {
                    if (st.empty()) return false;
    
                    if ((c == ')' && st.top() != '(') ||
                        (c == ']' && st.top() != '[') ||
                        (c == '}' && st.top() != '{')) {
                        return false;
                    }
    
                    st.pop();
                }
            }
    
            return st.empty();
        }
    };
    