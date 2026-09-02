# Problem 20

- **Link:** https://leetcode.com/problems/valid-parentheses/
- **Difficulty:** Easy   
- **Rating:** <e.g. 1650>
- **Date:** 2026-09-02
- **Topic(s):** Stacks
- **Pattern:** Stack poping if condition met, return value depends on stack emptiness

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: <mm:ss>

## Approach
1. Push to stack if open
2. Pop if the top matches the closed version of the current one
3. If its not empty isnt valid

## Complexity

- Time: `O(...)`
- Space: `O(...)`

## What I missed / got wrong
- Unnecessary maps, could make more optimized

## What I'd do differently next time
- Avoid using maps if a simpler method can work

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---