# Problem 239

- **Link:** https://leetcode.com/problems/sliding-window-maximum/
- **Difficulty:** Hard   
- **Rating:** <e.g. 1650>
- **Date:** 2026-09-14
- **Topic(s):** Arrays, Queues
- **Pattern:** Queue tracks all valid elements. New element prunes queue on both sides based on conditions (expired and greater/smaller than)

---

## Attempt

- [ ] Solved cold (no hints)
- [x] Solved with hints — stage reached:  `Hint 3` 
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: <mm:ss>

## Approach
1. On new element prune elements that have expired and prun elements from that back that are smaller than the new one as those can't appear again
2. Push back into solution the queue head
## Complexity

- Time: `O(n)`
- Space: `O(k)`

## What I missed / got wrong
- Using non continuous heap-allocated queue when i could just have a tail and head pointer to play the same role as the queue

## What I'd do differently next time

- Avoid heap reallocations on the hot path

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---