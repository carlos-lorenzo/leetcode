# Problem 22

- **Link:** https://leetcode.com/problems/generate-parentheses/
- **Difficulty:** Medium   
- **Rating:** 1600
- **Date:** 2026-08-21
- **Topic(s):** Recusrion
- **Pattern:** Backtracking - counting how many left of each posibility

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 08:00

## Approach
- Keep track of the amount left from each choice and backtrack with each one until no more left
- First character must always be `"("`and last `")"`
## Complexity


- Time: $O(n \cdot C_n)$
- Space: `O(2n)`

## What I missed / got wrong


## What I'd do differently next time
- Didn't pass current by reference
- Didn't reserve space upfront

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---