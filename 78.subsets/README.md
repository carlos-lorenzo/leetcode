# Problem 78

- **Link:** https://leetcode.com/problems/subsets/
- **Difficulty:** Medium   
- **Rating:** <e.g. 1650>
- **Date:** 2026-08-20
- **Topic(s):** Recursion - Backtracking
- **Pattern:** Backtracking but alwasy include the solution as you care for all possible sets, iterate choices (index) over [last choice + 1, choices.size()]

---

## Attempt

- [ ] Solved cold (no hints)
- [x] Solved with hints — stage reached: `Editorial intuition`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 05:00

## Approach
1. Include current solution
2. For every possible choice pick it, recurse and remove it

## Complexity

- Time: `O($2^n$)`
- Space: `O(n)`

## What I missed / got wrong
Not knowing how to implement backtracking

## What I'd do differently next time



## Review status

- [x] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---