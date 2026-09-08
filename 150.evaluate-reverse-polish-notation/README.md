# Problem 150

- **Link:** https://leetcode.com/problems/evaluate-reverse-polish-notation/
- **Difficulty:** Medium   
- **Rating:** <e.g. 1650>
- **Date:** 2026-09-08
- **Topic(s):** Stack
- **Pattern:** Pushing into stack if number, carry out operation with top 2 elements if operator encountered

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 05:00

## Approach
1a. Push into stack if number
1b. Pop top 2 numbers and carry out operation if operator
- Careful with division order as it matters 

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong
- My code wasnt super clean and shouldve used better variable names lhs/rhs instead of first and second
- Didnt implement however should use contiguous memory instead of normal stack and preallocate required memory for optimal performance

## What I'd do differently next time
- Think about readability and cleanness

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---