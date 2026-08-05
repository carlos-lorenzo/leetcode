// Category: algorithms
// Level: Medium
// Percent: 73.025925%



// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// 
//  
// Example 1:
// 
// 
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// 
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 
// Explanation:
// 
// 
// 	There is no string in strs that can be rearranged to form "bat".
// 	The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// 	The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// 
// 
// 
// Example 2:
// 
// 
// Input: strs = [""]
// 
// Output: [[""]]
// 
// 
// Example 3:
// 
// 
// Input: strs = ["a"]
// 
// Output: [["a"]]
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= strs.length <= 10⁴
// 	0 <= strs[i].length <= 100
// 	strs[i] consists of lowercase English letters.
// 
 

#include <unordered_map>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#endif

class Solution {
    public:
    
        struct ArrayHash {
            template <typename T, std::size_t N>
            std::size_t operator()(const std::array<T, N>& arr) const {
                std::size_t seed = N;
                for (const auto& elem : arr) {
                    // Standard hash combining algorithm
                    seed ^= std::hash<T>{}(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
                }
                return seed;
            }
        };
    
    
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
            constexpr size_t N_LETTERS = 26;
            vector<vector<string>> sol{};
            unordered_map<array<char, N_LETTERS>, size_t, ArrayHash> index_map{};
        
            
    
            // 1 pass solution, find all anagrams, if new solution anagram push back in solution array and index hashmap => O(nk) space and time
            for (const auto &s : strs) {
                array<char, N_LETTERS> letter_counts{};
                for (const auto &c : s) {
                    ++letter_counts[c - 'a'];
                }
                if (index_map.find(letter_counts) == index_map.end()) {
                    index_map[letter_counts] = sol.size();
                    sol.push_back({s});
                } else {
                    sol[index_map[letter_counts]].push_back(s);
                }
            }
            return sol;
        }
    };