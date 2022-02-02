# Binary Search


```cpp
int search(vector<int>& nums, int target){

  int first = 0;
  int last = nums.size()-1;

  int mid = (first+last)/2;
  while (first <= last){
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] > target)
      last = mid-1;
    else
      first = mid+1;
    mid = (first+last)/2;
  }
  return -1;
}
```
### Finding first/last occurrence of value

Essentially the same code, except have an extra variable `ans`,
and whenever we find a match, set this index to `ans` and continue
looking on the left or right side of the array.

```cpp
int search(vector<int>& nums, int target){

  int first = 0;
  int last = nums.size()-1;

  int ans = -1;
  while (first <= last){
    int mid = (first+last)/2;
    if (nums[mid] == target){
      ans = mid;
      last = mid-1; // first = mid+1 for last occurrence
    }
    else if (nums[mid] > target)
      last = mid-1;
    else
      first = mid+1;
  }
  return ans;
}
```

### Finding the index if target does not exist

If the target we are looking for is not in the array and we want
to know the index of target if it were in the array (that is, the index `i` such that `nums[i-1] < target` and `target < nums[i+1]`),
then we can modify the code as follows:

```cpp
int mid = (first+last)/2;
while(first <= last){
    if (nums[mid] == target)
      return mid;
    ...
    mid = (first+last)/2;
}

if (nums[mid] < target)
  return mid+1;
return mid;
```
sine `mid` is the last index that we checked, and it is either
smaller or bigger than target. 


Relevant questions:
- [https://leetcode.com/problems/binary-search](https://leetcode.com/problems/binary-search)
- [https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
