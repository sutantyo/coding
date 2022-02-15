# Quicksort

```cpp
void quicksort(vector<int>& nums, int start, int end){

  if (start >= end)
    return;
  int p = partition(nums,start,end);
  quicksort(nums,start,p-1);
  quicksort(nums,p+1,end);
}

int partition(vector<int>& nums, int start, int end){

  int pivot = nums[start];
  int f = start+1;
  int l = end+1;

  while(f < l){
    if (nums[f] <= pivot)
      f++;
    else{
      l--;
      swap(nums,f,l);
    }
  }
  swap(nums,start,f-1);
  return f-1;
}
```
Notes:
1. `f` is a pointer to the first unknown value, everything before
`f` is smaller than the pivot, and `l` is a pointer
to the first element that is larger than pivot.
2. Why stop when `f == l`? If `f == l`, then we know `nums[f]` is
bigger than pivot (or potentially out of bound)
3. Since we stop when `f == l`, we are guaranteed that `nums[f-1]`
is less than or equal to the pivot.

Relevant questions:
- [https://leetcode.com/problems/kth-largest-element-in-an-array/](https://leetcode.com/problems/kth-largest-element-in-an-array/)

### Dutch Flag Question (Quicksort Variant)

Sort an array of integers consisting only of 3 different values, e.g.
`[1,2,0,1,1,1,0,1,2,1]`.
 
```cpp
void sortColors(vector<int>& nums) {
  
  int f = -1;           // pointer to last occurrence of 0
  int l = nums.size();  // pointer to first occurrence of 2
  int u = 0;            // pointer to first unknown value
  
  while(u < l){
      if (nums[u] == 0){
          f++;
          swap(nums,u,f);
          u++;
      }
      else if (nums[u] == 1){
          u++;
      }
      else{ // nums[u] == 2
          l--;
          swap(nums,u,l);
      }
  }
}
```

Relevant questions:
- [https://leetcode.com/problems/sort-colors/](https://leetcode.com/problems/sort-colors/)