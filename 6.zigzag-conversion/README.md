# Problem 6

- **Link:** https://leetcode.com/problems/zigzag-conversion/
- **Difficulty:** Medium   
- **Rating:** <e.g. 1650>
- **Date:** 2026-09-26
- **Topic(s):** Arrays/Strings
- **Pattern:** Compute distance to next element and set at current location in solution array

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [x] Knew the pattern, execution had bugs
- Time to first working solution: 15:00

## Approach
- At each row you know the distance to the next letter, compute that and move the pointer over that distance
- If at top/bottom edge only go downward/upward in the middle alternate


## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong

- The algorithm isnt right if numRows = 1, that edge case must be handled by returing the original string


## What I'd do differently next time
- Avoid recomputing the distance to the next element as those are known beforehand
- Avoid having conditionals in the hot path, have separate loops

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---