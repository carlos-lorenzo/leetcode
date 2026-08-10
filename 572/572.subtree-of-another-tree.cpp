#include <cmath>
#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Easy
// Percent: 52.00703%



// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
// 
// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
// 
//  
// Example 1:
// 
// Input: root = [3,4,5,1,2], subRoot = [4,1,2]
// Output: true
// 
// 
// Example 2:
// 
// Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
// Output: false
// 
// 
//  
// Constraints:
// 
// 
// 	The number of nodes in the root tree is in the range [1, 2000].
// 	The number of nodes in the subRoot tree is in the range [1, 1000].
// 	-10⁴ <= root.val <= 10⁴
// 	-10⁴ <= subRoot.val <= 10⁴
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
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if (!root) [[unlikely]] return false;
            if (!subRoot) return true;
            if (isSubtree(root, subRoot)) return true;
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    
    private:
        bool same_tree(TreeNode* p, TreeNode* q) {
            if (p == q) return true; // Both nullptr
            if (!p || !q) return false; // One of them nullptr
            if (p->val != q->val) return false;
            return same_tree(p->left, q->left) && same_tree(p->right, q->right); 
        }
    };
