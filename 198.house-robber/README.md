# Problem 198

- **Link:** https://leetcode.com/problems/house-robber/
- **Difficulty:** Medium   
- **Rating:** <e.g. 1650>
- **Date:** 2026-10-26
- **Topic(s):** DP
- **Pattern:** Memoisation + Kadane's or Bottom Up DP

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 05:00
## Approach

- Recursively obtain max money at each index, store result in cache and use that cache to avoid repeated behaviour
- At each step you can either rob this house or skip it and rob the next. Therefore the value at each point is: `max(current + (current + 2), (current+1))`

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong

I could've used bottom up dp where you store 2 values intead of an array and a loop instead of recursion

## What I'd do differently next time
Avoid recursion if possible and use the bottom up approach

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---