# Problem 236

- **Link:** https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
- **Difficulty:** Medium   
- **Rating:** <e.g. 1650>
- **Date:** 2026-08-13
- **Topic(s):** Trees
- **Pattern:** DFS - bottom up

---

## Attempt

- [ ] Solved cold (no hints)
- [x] Solved with hints — stage reached: `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [x] Knew the pattern, execution had bugs
- Time to first working solution: <mm:ss>

## Approach
- Retturn root if root is nullptr, p or q
- Recursively check if left/right is p, q or null
- If both non-null root is lca
- Else p/q is within a subtree of the other one, ie p is the root of q or viceversa => return the non null tree node since that is the root

## Complexity

- Time: `O(...)`
- Space: `O(...)`

## What I missed / got wrong
- Bottom up didnt know how to

## What I'd do differently next time
- Base case -> left/right recursion -> aggregationi -> return aggregation

## Review status

- [x] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---