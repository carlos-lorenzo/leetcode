# Problem 239

- **Link:** https://leetcode.com/problems/sliding-window-maximum/
- **Difficulty:** Hard   
- **Rating:** 1600
- **Date:** 2026-08-04
- **Topic(s):** Arrays, Queues
- **Pattern:** Dequeue storing indices such that front/back have a condition

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [x] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 10:00

## Approach
- Create a dequeue (doble ended queue) that tracks the indices
- Each iteration prune the indices that have left the window from the from
- Each iteration prune the indicies that don't meet the condition (max in this case => smaller than the new one) as they can no longer be a max value
- Push the new value back

## Complexity

- Time: `O(n)`
- Space: `O(n)` (Aux `O(k)`)

## What I missed / got wrong
- I missed that I had to use queue, I reviewed the solution, understood it and attempted it the day after

## What I'd do differently next time
- If I need the running maximum/minimum with a distance/time limit, use a monotonic dequeue
## Review status

- [x] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---