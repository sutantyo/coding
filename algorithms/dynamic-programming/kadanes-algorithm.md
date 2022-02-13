# Kadane's Algorithm

### Kadane's Algorithm (Maximum Subarray Sum)

Kadane's algorithm is used to find the contiguous subarray with 
the largest sum, for example, given the array 
`[ 1, -3, 4, -2, 5, -3, 2]`, then the subarray with the maximum
sum is `[4, -2, 5]`. 
```cpp
int kadane(vector<int>& nums){
  
  int best = nums[0];
  int sum = max(0,best);
  for(int i = 1; i < n; i++){
    sum += nums[i];
    if (sum < 0) 
      sum = 0;
    if (sum > best) 
      best = sum;
  }
}
```
A common question using this algorithm asks us to find the best
time to buy and then sell a share, given the history of the share
prices. This is equivalent to the maximum subarray sum problem
because if we construct an array of share price movements, then
the best gain from buying and selling is the subarray of
with the maximum sum.

Here is the same algorithm with this setup
```cpp
int low = prices[0];
int profit = 0;

for(int i = 1; i < prices.size(); i++){
    if (low < prices[i]){
        profit = max(profit,prices[i]-low);
    }
    if (prices[i] < low)
        low = prices[i];
}
return profit;
```

The algorithm can also 
be adapted to find the contiguous subarray with the 
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
- [https://leetcode.com/problems/best-time-to-buy-and-sell-stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock)
- [https://leetcode.com/problems/maximum-subarray](https://leetcode.com/problems/maximum-subarray)
- [https://leetcode.com/problems/maximum-product-subarray](https://leetcode.com/problems/maximum-product-subarray)