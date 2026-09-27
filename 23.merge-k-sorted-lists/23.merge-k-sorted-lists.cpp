#if __has_include("leetcode.hpp")
#include "leetcode.hpp"
#elif __has_include("../leetcode.hpp")
#include "../leetcode.hpp"
#endif

// Category: algorithms
// Level: Hard
// Percent: 60.15176%



// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// 
// Merge all the linked-lists into one sorted linked-list and return it.
// 
//  
// Example 1:
// 
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6
// 
// 
// Example 2:
// 
// Input: lists = []
// Output: []
// 
// 
// Example 3:
// 
// Input: lists = [[]]
// Output: []
// 
// 
//  
// Constraints:
// 
// 
// 	k == lists.length
// 	0 <= k <= 10⁴
// 	0 <= lists[i].length <= 500
// 	-10⁴ <= lists[i][j] <= 10⁴
// 	lists[i] is sorted in ascending order.
// 	The sum of lists[i].length will not exceed 10⁴.
// 
 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if (lists.empty()) return nullptr;
            
    
            vector<ListNode*> solution = lists;
    
            while (solution.size() > 1) {
                // for (const auto& element : solution) std::cout << *element << ", ";
                vector<ListNode*> new_solution{};
                new_solution.reserve(solution.size()/2+1);
                for (size_t i=0; i<solution.size() - solution.size()%2; i+=2) {
                    new_solution.push_back(merge_pair(solution[i], solution[i+1]));
                }
                if (solution.size() % 2 == 1) new_solution.push_back(solution[solution.size() - 1]);
                solution = new_solution;
            }
            
            return solution[0];
        }
    
        void push(ListNode* node, ListNode*& head, ListNode*& tail) {
            if (!node) return;
    
            if (!head) {
                head = tail = node;
                return;
            }
    
            tail->next = node;
            tail = node;
        }
    
        void pop_head(ListNode*& head) {
            if (!head) return;
    
            head = head->next;
    
        }
    
        ListNode* merge_pair(ListNode* left, ListNode* right) {
            ListNode* head{};
            ListNode* tail{};
            ListNode* to_push{};
            while (left || right) {
                // Since either left or right are populated we first check if either is missing as both can't be
                if (!left) to_push = right;
                else if (!right) to_push = left;
                else if (right->val < left->val) to_push = right;
                else to_push = left;
    
                if (to_push == left) {
                    push(left, head, tail);
                    pop_head(left);
                } else {
                    push(right, head, tail);
                    pop_head(right);
                }
            }
    
            return head;
        }
    };
    
