# Problem 739

- **Link:** https://leetcode.com/problems/daily-temperatures/
- **Difficulty:** Medium   
- **Rating:** 1650
- **Date:** 2026-09-14
- **Topic(s):** Stacks
- **Pattern:** Stickly increasing/decreasing index tracking stack due to conditions (pruned if larger that current element)

---

## Attempt

- [ ] Solved cold (no hints)
- [x] Solved with hints — stage reached: `Hint 2`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 15:00

## Approach
1. While the stack isnt empty remove elemnts from the top if they're smaller than the current temperature
2. Set solution[stack.top()] = i - stack.top()
3. Push the current element

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong
- Failed to realise that i could exploit the problems conditions to obtain a strickly decreasing stack

## What I'd do differently next time
Think about how pruning can be used when a new element comes along

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---