# Problem 190

- **Link:** https://leetcode.com/problems/reverse-bits/
- **Difficulty:** Easy   
- **Rating:** <e.g. 1650>
- **Date:** 2026-10-07
- **Topic(s):** Bit manipulation
- **Pattern:** LUT. Precalculate values for bytes and split into 4 bytes

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 10:00

## Approach
- Original num can be though of: (Byte 3) (Byte 2) (Byte 1) (Byte 0)
- Each byte is reversed independently with the LUT
- Then reorganize the bytes such that new order is (Byte0) (Byte 1) (Byte 2) (Byte 3)

## Complexity

- Time: `O(1)`
- Space: `O(1)`

## What I missed / got wrong


## What I'd do differently next time


## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---