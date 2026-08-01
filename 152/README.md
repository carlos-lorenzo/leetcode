# Problem 152

- **Link:** https://leetcode.com/problems/maximum-product-subarray/
- **Difficulty:** Medium   
- **Rating:** <e.g. 1650>
- **Date:** 2026-08-01
- **Topic(s):** <e.g. Trees, Two Pointers>
- **Pattern:** <one line — the reusable pattern this maps to, matches your topic-notes Pattern Catalog>

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [x] Knew the pattern, execution had bugs
- Time to first working solution: 10:00

## Approach
- Kadane's but with 2 local states (`local_max` and `local_min`)
- At each step consider possible new max and min and set `local_max` and `local_min` accordingly.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## What I missed / got wrong
- My solution is not technically the canonical solution. I mapped my idea of reseting from 0 on the sum to 1 in multiplication which worked. My solution was broken until i realized i had to swap 0 (summatory identity) for 1 (multiplicative identity)
- However the canonical solution is much simpler and doesnt involve `local_best` and `local_worst` 
Simply: `int temp_max = std::max({num, local_max * num, local_min * num});` or even better (doesn't really matter thanks to compiler optimisations): `local_max = std::max(num, std::max(prod1, prod2));`

## What I'd do differently next time
- Make solution more readable by applying max and min with more values (I didn't know you could do that by turning into an array)

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---