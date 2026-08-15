// Category: algorithms
// Level: Medium
// Percent: 73.242226%



// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
// 
//  
// Example 1:
// 
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// 
// 
// Example 2:
// 
// Input: root = [1]
// Output: [[1]]
// 
// 
// Example 3:
// 
// Input: root = []
// Output: []
// 
// 
//  
// Constraints:
// 
// 
// 	The number of nodes in the tree is in the range [0, 2000].
// 	-1000 <= Node.val <= 1000
// 
 
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #include <vector>
 #include <queue>
 
 class Solution {
 public:
     std::vector<std::vector<int>> levelOrder(TreeNode* root) {
         if (!root) return {};
 
         std::vector<std::vector<int>> sol;
         std::queue<TreeNode*> q;
         q.push(root);
 
         while (!q.empty()) {
             const size_t level_size = q.size();
             std::vector<int> level;
             level.reserve(level_size); // Optimize memory allocations
 
             for (size_t i = 0; i < level_size; ++i) {
                 TreeNode* node = q.front();
                 q.pop();
 
                 level.push_back(node->val);
 
                 // Guard child enqueuing to prevent queue bloat and nullptr iterations
                 if (node->left)  q.push(node->left);
                 if (node->right) q.push(node->right);
             }
 
             sol.push_back(std::move(level)); // Move level vector to eliminate copying
         }
 
         return sol;
     }
 };