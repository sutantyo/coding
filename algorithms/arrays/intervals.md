# Intervals

### Overlapping intervals

To determine if two intervals `[a,b]` and `[c,d]`
are overlapping:
```
   min(b,d) > max(a,c)
```
or conversely, if they are NOT overlapping, then
the minimum of the ends must be smaller than the 
maximum of the starts.

### Detecting overlap on a series of intervals

If we are given a series of intervals and asked to
see if any two intervals are overlapping, then
rather than doing a `O(n^2)` pairwise comparison,
we can sort all the intervals first, and then see
if any of the intervals starts before the previous
one ends.

Relevant Questions:
- [LeetCode 252 - Meeting Rooms](https://leetcode.com/problems/meeting-rooms/)
- [LeetCode 253 - Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)
   - determine how many rooms are needed (use priority queue)






