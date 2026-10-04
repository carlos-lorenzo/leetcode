# Problem 136

- **Link:** https://leetcode.com/problems/single-number/
- **Difficulty:** Easy   
- **Rating:** <e.g. 1650>
- **Date:** 2026-10-04
- **Topic(s):** Bit manipulation
- **Pattern:** XOR checksum: XOR applied twice leaves value unchanged

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: <mm:ss>

## Approach
- XOR every number together, since same value XOR with itself returns 0, after XORing the value left is the only one that isn't duplicate

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## What I missed / got wrong

<Be specific: wrong initial data structure, missed an edge case, misjudged complexity,
froze on the observation step, clean logic but slow typing, etc. This is the line that
actually earns you something on review — vague notes here are wasted effort.>

## What I'd do differently next time

<One or two concrete adjustments — a trigger phrase to add to Recognition Triggers,
a variant to add to the Pattern Catalog, a habit to change (e.g. "write the invariant
down before coding").>

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---