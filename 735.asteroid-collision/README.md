# Problem 735

- **Link:** https://leetcode.com/problems/asteroid-collision/
- **Difficulty:** Medium   
- **Rating:** <e.g. 1650>
- **Date:** 2026-09-04
- **Topic(s):** Stack
- **Pattern:** Push and pop conditionally

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 20:00

## Approach
1. For every new asteroid check if it collides. Push if doesnt resolve if it does
2. If collides and smaller, dont do anything
3. If colides and larger, check with next element.
4. goto 1 (recurse and re check with the new asteroid until the list is empty in which case you push, it collides and is smaller in which case do nothing, it doesnt collide, in which case push)

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong
- Solution not super clean

## What I'd do differently next time
- Cleaner code by simplifying conditionals, looping and perhaps use recursion for this problem

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---