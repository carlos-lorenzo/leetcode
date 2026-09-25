# Problem 18

- **Link:** https://leetcode.com/problems/4sum/
- **Difficulty:** Medium   
- **Rating:** <e.g. 1650>
- **Date:** 2026-09-25
- **Topic(s):** <e.g. Trees, Two Pointers>
- **Pattern:** Same as 3sum but you fix 2 variables
---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 20:00

## Approach
- Sort array
- fix 2 values and check that you have not already solved for the current combination of fixed values (current != previous)
- while left < right... check every solution and move left/right according to the solution being too large/too small since the array is sorted
- If a solution is found move left and right until they are different

## Complexity

- Time: `O(n^3)`
- Space: `O(1)`

## What I missed / got wrong
- Many of the edge cases and overflows, general algorithm from the beggining but the edge cases got me hard

## What I'd do differently next time


## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---