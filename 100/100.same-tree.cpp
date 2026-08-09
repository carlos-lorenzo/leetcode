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

#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> nodes{};
        nodes.push({p, q});

        while (nodes.size() > 0) {
            auto [np, nq] = nodes.front();
            nodes.pop();
            if (!np && !nq) continue;
            if ((!np || !nq) || np->val != nq->val) return false;
            nodes.push({np->left, nq->left});
            nodes.push({np->right, nq->right});
        }
        return true;      
    }
};
