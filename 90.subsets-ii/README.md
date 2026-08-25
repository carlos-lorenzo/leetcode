# Problem 90

- **Link:** https://leetcode.com/problems/subsets-ii/
- **Difficulty:** Medium   
- **Rating:** <e.g. 1650>
- **Date:** 2026-08-24
- **Topic(s):** <e.g. Trees, Two Pointers>
- **Pattern:** Backtracking -> Sortig beforehand

---

## Attempt

- [ ] Solved cold (no hints)
- [x] Solved with hints — stage reached: `Editorial title` 
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 30:00

## Approach
- Sort the input
- Backtrack normally like subsets
- Allow an addition of a number if it has not been added already to the current solution. Since the input numbers are sorted, my solutions will too be. Therefore just check by: i > start (avoids out of bounds checking for first interation) && nums[i] == nums[i-1]

## Complexity

- Time: `O($O(N \cdot 2^N)$)`
- Space: `O(N)` (auxiliary)

## What I missed / got wrong

- Doing a log(n) (emplace range) duplicate checking instead of the simpler O(1)
- Allocation variables as a class variables instead of passing them as function arguments as I though that would allocated them to the stack but i was wrong
- Unnecessarily using an unordered_map (heap allocations = BAD)

## What I'd do differently next time
- No unordered_maps or any heap-reliant ds
- Not fully exploiting the sorted input

## Review status

- [x] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---