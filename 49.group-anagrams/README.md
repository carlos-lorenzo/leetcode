# Problem 49

- **Link:** https://leetcode.com/problems/group-anagrams/
- **Difficulty:** Medium   
- **Rating:** 1600
- **Date:** 2026-08-05
- **Topic(s):** Strings
- **Pattern:** Frequency counting with fixed size array and hashmap

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [x] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 10:00

## Approach
- Hashmap -> anagram : array index
- Find array representing hashmap as max characters fixed => frequency counting efficient

## Complexity

- Time: `O(nk)`
- Space: `O(n)`

## What I missed / got wrong
- Using char instead of int for key as it can overflow

## What I'd do differently next time

- Using int instead of char
- Using try_emplace combines the bucket lookup and insertion into a single atomic operation, bypassing the eager object construction penalty of standard .insert().

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---