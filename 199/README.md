# Problem 199

- **Link:** https://leetcode.com/problems/binary-tree-right-side-view/
- **Difficulty:** Medium   
- **Rating:** <e.g. 1650>
- **Date:** 2026-08-09
- **Topic(s):** Tree
- **Pattern:** BFS with level loop

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 10:00

## Approach
- BFS, append to solution the first element in each element as its the rightmost
- When pushing to queue push right child first

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong
- Forgot to check for null root on first submit

## What I'd do differently next time
- Use DFS as its more efficen that BFS for this problem
- Avoid quees and dymanically allocating memory => use reserve(100) at the start (100 as defined by problem contraints)

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---