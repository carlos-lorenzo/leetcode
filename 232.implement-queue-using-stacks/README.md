# Problem 232

- **Link:** https://leetcode.com/problems/implement-queue-using-stacks/
- **Difficulty:** Easy   
- **Rating:** <e.g. 1650>
- **Date:** 2026-09-02
- **Topic(s):** Stack
- **Pattern:** 2 stacks, reverser order of first when needed, change default allocator

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 10:00

## Approach
- 2 stacks, defined with using as having a vector
- When need to access first, reverse order by pushing in out (this is done sparsely)

## Complexity

- Time: `O(1)`
- Space: `O(n)`

## What I missed / got wrong
- Didnt change dequeue to vector

## What I'd do differently next time
- Denote noexcept when conditions meet
- Make underlying structure a vector

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---