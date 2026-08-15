# Problem 543

- **Link:** https://leetcode.com/problems/diameter-of-binary-tree/
- **Difficulty:** Easy   
- **Rating:** <e.g. 1650>
- **Date:** 2026-08-13
- **Topic(s):** Trees
- **Pattern:** DFS - Bottom Up

---

## Attempt

- [ ] Solved cold (no hints)
- [x] Solved with hints — stage reached: `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 20:00

## Approach
- DFS Bottom up to compute the depth of each branch 
- As it up unwinds back up update global max based on each of branhes
- Pass max_diamater by reference into aux function to allow it to be updated and return max_diamter
- The aux function recursively dfs-bottom up computes each branches depth

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong
- Did't know how to implement bottom up

## What I'd do differently next time
- Base case -> left/right recursion -> aggregationi -> return aggregation

## Review status

- [x] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---