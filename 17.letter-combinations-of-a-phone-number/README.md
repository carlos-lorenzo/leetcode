# Problem 17

- **Link:** https://leetcode.com/problems/letter-combinations-of-a-phone-number/
- **Difficulty:** Medium   
- **Rating:** 1600
- **Date:** 2026-08-22
- **Topic(s):** Recursion - Backtracking
- **Pattern:** Backtracking map input to choice list and pass index of current choice

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 15:00

## Approach
- Store the choices corresponding to each digit
- For each digit try each choice

## Complexity

- Time: `O(n * 4^n)`
- Space: `O(n * 4^n)`

## What I missed / got wrong
- Setting noexcept when unordered_map.at can throw an std::out_of_range

## What I'd do differently next time
- Use arrays and string view instead of unordered map and vec to avoid using the heap

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---