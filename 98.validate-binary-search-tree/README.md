# Problem 98

- **Link:** https://leetcode.com/problems/validate-binary-search-tree/
- **Difficulty:** Medium   
- **Rating:** <e.g. 1650>
- **Date:** 2026-08-15
- **Topic(s):** <e.g. Trees, Two Pointers>
- **Pattern:** <one line — the reusable pattern this maps to, matches your topic-notes Pattern Catalog>

---

## Attempt

- [ ] Solved cold (no hints)
- [x] Solved with hints — stage reached:  `Editorial intuition` 
- [ ] Recognized the pattern immediately but implementation was slow
- [x] Knew the pattern, execution had bugs
- Time to first working solution: 15:00

## Approach
- Check condition first
- Return left and right recursively

## Complexity

- Time: `O(N)`
- Space: `O(H)`

## What I missed / got wrong
- Returning left and right as i was ignoring the return values as i was treating it like an iterative approach
- The bounds were being set incorrectly: when checking left (small) the max value is the current root and the min value as low as you want to be, oppsite for right. As recursion gets deeper, the conditions get tighter ie after left->right you are now bounded on both sides

## What I'd do differently next time
- Check for null first and return accordingly (true in this case)
- Return left and right

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---