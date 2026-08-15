# Problem 217

- **Link:** https://leetcode.com/problems/contains-duplicate/
- **Difficulty:** Easy   
- **Rating:** TBD
- **Date:** 2026-07-31
- **Topic(s):** Arrays
- **Pattern:** Hashmap - track seen

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: <mm:ss>

## Approach

Same as 2-sum. Track seen values until you see the same one again where you return true, else return false

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## What I missed / got wrong

Nothing.

## What I'd do differently next time

- Could use `unordered_set` as O only care if it exitst.
- Use range base loop instead of indexing: `for (int x : nums)`
- Reserve size beforehand (`nums.size()`)
- Use `if (seen.find(nums[i]) != seen.end())` to improve compatibility

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---