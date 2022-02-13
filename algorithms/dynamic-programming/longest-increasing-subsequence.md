#  Longest Increasing Subsequence

````cpp

```https://leetcode.com/problems/best-time-to-buy-and-sell-

### Variants

 The question [increasing triplet subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/submissions/) is a special case of finding
 if there are any increasing subsequence of size 3, and the 
```cpp
        int a = nums[0];
        int b = INT_MAX;
        
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] < a)
                a = nums[i];
            if (nums[i] < b && nums[i] > a)
                smallest_with_1 = nums[i];
            if (nums[i] > smallest_with_1)
                return true;
        }
        return false;
````

https://leetcode.com/problems/increasing-triplet-subsequence/submissions/
