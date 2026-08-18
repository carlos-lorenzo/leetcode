# Problem 124

- **Link:** https://leetcode.com/problems/binary-tree-maximum-path-sum/
- **Difficulty:** Hard   
- **Rating:** 1600
- **Date:** 2026-08-18
- **Topic(s):** Trees (DFS), DP (Kadane's)
- **Pattern:** Bottom up DFS update global at each node. Max is sum of current val + max of each side. Return the side with highest sum
---

## Attempt

- [ ] Solved cold (no hints)
- [x] Solved with hints — stage reached: `Editorial intuition` 
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 05:00

## Approach
- Recursive bottom up DFS:
> 1. Return 0 if empty
> 2. Call max(0, left) and max(0, right)
> 3. Update global max currr + left + right
> 4. Return curr + max(left, right)
- You traverse to the last node and recursively climb up at each node checking if having the current node as the peak is better than global max, return the side with higest yield as that will allow the next node up to use its childs highest yielding path to check its own

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong
- Not fully understanding how to implement bottom up apprroach => returning global max instead of current math and setting global max to curent max instead of true possible global max

## What I'd do differently next time
- Clearly think what the function needs to return => that will be ouput of calling to left on right, ie the data i need at the top is what i will return at the end
- Update state in the middle

## Review status

- [x] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---