# Problem 338

- **Link:** https://leetcode.com/problems/counting-bits/
- **Difficulty:** Easy   
- **Rating:** <e.g. 1650>
- **Date:** 2026-09-28
- **Topic(s):** Dinamic Programming
- **Pattern:** Reused previously computed bits and compare the new one
---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: <mm:ss>

## Approach
- For each number set the number of bits to the corresponding previous power of 2 (in that section) + 1 if the current i is odd

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong
I missed the DP approach and simply did nlogk with Brian Kernighan’s Algorithm

## What I'd do differently next time

<One or two concrete adjustments — a trigger phrase to add to Recognition Triggers,
a variant to add to the Pattern Catalog, a habit to change (e.g. "write the invariant
down before coding").>

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---