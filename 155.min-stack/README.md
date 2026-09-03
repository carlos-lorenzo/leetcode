# Problem 155

- **Link:** https://leetcode.com/problems/min-stack/
- **Difficulty:** Medium   
- **Rating:** 1600
- **Date:** 2026-09-03
- **Topic(s):** Stacks
- **Pattern:** Store alongise each element the tracked variable at the point of insertion

---

## Attempt

- [ ] Solved cold (no hints)
- [x] Solved with hints — stage reached:  `Hint 1` 
- [ ] Recognized the pattern immediately but implementation was slow
- [ ] Knew the pattern, execution had bugs
- Time to first working solution: <mm:ss>

## Approach
- When pushing find the current min value
> - Min value: std::min(value, data_.top().second) <- stack stored as pair, as i havent yet pushed, second represented the min value up until that point in time
- Implement the rest as normal

## Complexity

- Time: `O(1)`
- Space: `O(n)`

## What I missed / got wrong
- I didnt need to track a current_min_ to handle the edge case of the first number

## What I'd do differently next time
- Thinking about what information can be tracked by the stack/queue given in time-dependant nature

## Review status

- [ ] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---