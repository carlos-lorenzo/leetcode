# Problem 46

- **Link:** https://leetcode.com/problems/permutations/
- **Difficulty:** Medium   
- **Rating:** 1600
- **Date:** 2026-09-01
- **Topic(s):** Backtracking
- **Pattern:** Remove choice from choice pool, then restore pool after backtracking

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: <mm:ss>

## Approach
- Remove choice from choice pool, then restore pool after backtracking

## Complexity

- Time: `O(n·n!)`
- Space: `O(n)`

## What I missed / got wrong
- Not knowing swap existed
- Forgetting to undo my choice properlly with swap again

## What I'd do differently next time
- Use contiguous memory and inplace modification to avoid cache misses and heap access

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---