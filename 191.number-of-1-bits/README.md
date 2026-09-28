# Problem 191

- **Link:** https://leetcode.com/problems/number-of-1-bits/
- **Difficulty:** Easy   
- **Rating:** <e.g. 1650>
- **Date:** 2026-09-28
- **Topic(s):** Bit manipulation
- **Pattern:** Brian Kernighan’s Algorithm

---

## Attempt

- [x] Solved cold (no hints) (My alternative)
- [x] Solved with hints — stage reached: `Full solution` (Brian Kernighan’s Algorithm)
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 00:30

## Approach
- Bitwise AND n with n-1 to set the least significant bit to 0
- Repeat until n == 0 and count the number of iterations

- Alternatively bitwise and with ```1u<<i``` where i goes from 0 to 31, if the result is 1, add 1 to count
## Complexity

- Time: `O(n)` (mine) `O(k)` Brian Kernighan’s Algorithm (where k is number of bits)
- Space: `O(1)`

## What I missed / got wrong
- Nothing, simply learned the algorithm


## What I'd do differently next time
- Brian Kernighan’s Algorithm only iterates if the bit is a 1 so it avoids unnecessary work

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---