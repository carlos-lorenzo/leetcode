#include <cstddef>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Medium
// Percent: 70.91722%



// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
// 
//  
// Example 1:
// 
// 
// Input: root = [1,2,3,null,5,null,4]
// 
// Output: [1,3,4]
// 
// Explanation:
// 
// 
// 
// 
// Example 2:
// 
// 
// Input: root = [1,2,3,4,null,null,null,5]
// 
// Output: [1,3,4,5]
// 
// Explanation:
// 
// 
// 
// 
// Example 3:
// 
// 
// Input: root = [1,null,3]
// 
// Output: [1,3]
// 
// 
// Example 4:
// 
// 
// Input: root = []
// 
// Output: []
// 
// 
//  
// Constraints:
// 
// 
// 	The number of nodes in the tree is in the range [0, 100].
// 	-100 <= Node.val <= 100
// 
 

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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> sol;
        if (!root) return {};
        q.push(root);

        while (!q.empty()) {
            auto level_size = q.size();

            for (size_t i=0; i<level_size; ++i) {
                auto node = q.front();
                q.pop();
                if (i==0) sol.push_back(node->val);
                if (node->right) q.push(node->right); // Order crucial as we're looking from the right side
                if (node->left) q.push(node->left); 
            }
        }
        return sol;

    }
};

// Better solution

// class Solution {
//     public:
//         std::vector<int> rightSideView(const TreeNode* const root) noexcept {
//             std::vector<int> result;
//             if (!root) [[unlikely]] {
//                 return result;
//             }
    
//             // According to constraints, max nodes = 100, max tree height <= 100.
//             // Pre-reserve to eliminate all runtime reallocations on the hot path.
//             result.reserve(100);
    
//             dfs(root, 0, result);
//             return result;
//         }
    
//     private:
//         void dfs(const TreeNode* const node, const std::size_t depth, std::vector<int>& result) noexcept {
//             if (!node) return;
    
//             // Since we traverse Right branch first, the first node encountered 
//             // at any given depth is guaranteed to be the rightmost visible node.
//             if (depth == result.size()) {
//                 result.push_back(node->val);
//             }
    
//             dfs(node->right, depth + 1, result);
//             dfs(node->left, depth + 1, result);
//         }
//     };