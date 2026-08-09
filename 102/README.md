# Problem 102

- **Link:** https://leetcode.com/problems/binary-tree-level-order-traversal/
- **Difficulty:** Medium   
- **Rating:** 1650
- **Date:** 2026-08-09
- **Topic(s):** Tree
- **Pattern:** BFS, iterate per level: while -> for

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 05:00

## Approach

<2-4 sentences, own words, the key insight — not a full walkthrough. This should read
like one entry in your topic-notes Pattern Catalog.>

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong
- Didnt check for empty root
- Didnt check for empty child before adding to queue

## What I'd do differently next time
- Use move to avoid copying
- Check if child null before appending to ensure no empty arrays appended to solution
- Check for root at the start, me having the empty check saved me but should check for empty root first thing

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---