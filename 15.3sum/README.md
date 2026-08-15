# Problem 15

- **Link:** https://leetcode.com/problems/3sum/
- **Difficulty:** Medium   
- **Rating:** 1600
- **Date:** 2026-08-02
- **Topic(s):** Arrays, 2 pointers
- **Pattern:** Sorted array -> exploit 2 pointers + fixed pointer

---

## Attempt

- [ ] Solved cold (no hints)
- [x] Solved with hints — stage reached: `Full solution`
- [x] Recognized the pattern immediately but implementation was slow
- [x] Knew the pattern, execution had bugs
- Time to first working solution: 65:00

## Approach

- Sort array and fix one element, then you use 2-pointers to find the missing 2 numbers since $x+y+z=0$ and since $x$ is known, $y+z=-x$
- Since you have 3 poiters (fixed + movable) simply check for each for duplicates => ensure the new pointer isnt equal to the past one => while loop

## Complexity

- Time: `O(n^2)`
- Space: `O(n^2)` (`O(1)` auxiliary as only keep track of 3 pointers + sorting space complexity)

## What I missed / got wrong
First attempted cold after completing the list of study problems, i knew i had to fix one value and check ofther the rest however i didn't try sorting the array so i tried simple 2 sum + fixed however duplicate checking was the toughest for that approach and
once i read about sorting first. I reviewed the solution yesterday, today i re-attempted and needed some hints since even though I new what i was doing my implementation had suble bugs.

## What I'd do differently next time
- Exploit sorting -> if solution time complexity greater than `O(nlogn)`, sort first and then use 2 pointers since sorted input is trigger for 2 pointers -> subproblem solvable in `O(n)`
- 

## Review status

- [x] `todo-review` — could not solve cold on first pass, revisit next review round
- [ ] Reviewed on <date> — resolved without hints, tag removed
- [ ] Reviewed on <date> — still shaky, stays tagged

---