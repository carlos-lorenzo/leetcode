# Problem 225

- **Link:** https://leetcode.com/problems/implement-stack-using-queues/
- **Difficulty:** Easy   
- **Rating:** <e.g. 1650>
- **Date:** 2026-09-08
- **Topic(s):** stacks, queues
- **Pattern:** 2 queues, move everything but the last element to another queue 

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 10:00

## Approach
- 2 Queues
- Push into the input queue
- When you want to fetch/pop move everything but the last element in the queue to a second queue
- Read that missing element (after swapping in and out)

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong
- My initial solution used swap which although optimial wasnt allowed

## What I'd do differently next time


## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---