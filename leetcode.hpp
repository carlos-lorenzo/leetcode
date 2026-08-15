#pragma once

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

// Converts string representation "[3,9,20,null,null,15,7]" to TreeNode*
inline TreeNode* stringToTreeNode(string input) {
    if (input.empty() || input == "[]") return nullptr;
    if (input.front() == '[') input = input.substr(1, input.length() - 2);
    stringstream ss(input);
    string item;
    if (!getline(ss, item, ',')) return nullptr;

    auto trim = [](string s) {
        size_t first = s.find_first_not_of(" \t\n\r");
        if (first == string::npos) return string("");
        size_t last = s.find_last_not_of(" \t\n\r");
        return s.substr(first, (last - first + 1));
    };

    item = trim(item);
    if (item == "null" || item.empty()) return nullptr;

    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (!getline(ss, item, ',')) break;
        item = trim(item);
        if (item != "null" && !item.empty()) {
            node->left = new TreeNode(stoi(item));
            q.push(node->left);
        }

        if (!getline(ss, item, ',')) break;
        item = trim(item);
        if (item != "null" && !item.empty()) {
            node->right = new TreeNode(stoi(item));
            q.push(node->right);
        }
    }
    return root;
}

