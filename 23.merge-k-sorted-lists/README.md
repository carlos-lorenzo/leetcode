# Problem 23

- **Link:** https://leetcode.com/problems/merge-k-sorted-lists/
- **Difficulty:** Hard   
- **Rating:** <e.g. 1650>
- **Date:** 2026-09-27
- **Topic(s):** Linked lists, divide and conquer, merge sort, arrays
- **Pattern:** Merge sort

---

## Attempt

- [x] Solved cold (no hints)
- [ ] Solved with hints — stage reached: `10min stuck` / `Hint 1` / `Hint 2` / `Topic tag` / `Editorial title` / `Editorial intuition` / `Full solution`
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: 30:00

## Approach
- Literally implement merge sort:
> - Pair up lists and make a sorter array with them

## Complexity

- Time: `O(nlogk)`
- Space: `O(n)`

## What I missed / got wrong
- This approach is not memory efficent and relies on heap reallocations, instead heaps should be used instead as they provide the same time complexity and carry out all operations in place, in the stack

## What I'd do differently next time
- Keep in mind that heaps exist
- Avoid calling my own helper functions in the hotpath if they are not inline. Ie inline my helper functions

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---