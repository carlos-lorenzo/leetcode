# Problem 121

- **Link:** https://leetcode.com/problems/same-tree/
- **Difficulty:** Easy   
- **Rating:** TBD
- **Date:** 2026-07-31
- **Topic(s):** Trees
- **Pattern:** BFS

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 10:00

## Approach
- BFS, store queue with pairs of same node (same level, same side)
- Check for nullptr and then check if values match
## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong

- First approach used 2 differnt queues and unorthodox nullptr chcking, new approach much cleaner

## What I'd do differently next time
- 2 queues in same queue if in pairs
- Better nulltpr checking

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---