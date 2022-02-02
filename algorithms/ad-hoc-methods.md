#Ad-hoc Methods

### Kadane's Algorithm (Maximum Subarray Sum)

Kadane's algorithm to find the contiguous subarray with 
the largest sum.

```cpp
int kadane(vector<int>& nums){
  
  int best = nums[0];
  int sum = max(0,best);
  for(int i = 1; i < n; i++){
    sum += nums[i];
    if (sum < 0) sum = 0;
    if (sum > best) best = sum;
  }
}
```
It can be adapted to find the contiguous subarray with the 
largest product. The difference is that we have to keep track of
negative products as well (since multiplying with
another negative number may create a large product).

```cpp
int kadane_product(vector<int>& nums){

  int high = nums[0];  // highest sum so far
  int low = nums[0];   // lowest sum so far (to handle negatives)
  int best = nums[0];

  for(int i = 1; i < n; i++){
    int temp = max(nums[i],max(high*nums[i],low*nums[i]));
    int low = min(nums[i],min(high*nums[i],low*nums[i]));
    high = temp;
    if (best < high)
      best = high;
  }
  return best;
}
```



Relevant questions:
- [https://leetcode.com/problems/maximum-subarray](https://leetcode.com/problems/maximum-subarray)
- [https://leetcode.com/problems/maximum-product-subarray](https://leetcode.com/problems/maximum-product-subarray)