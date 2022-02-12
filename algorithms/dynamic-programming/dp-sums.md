# DP - Sums

## Coin Change

Top-down approach:

```cpp
vector<int> dp;

int coin_change(vector<int>& coins, int amount) {
  dp.resize(amount+1,0);
  return coin_change(coins,amount);
}

int coin_change_helper(vector<int>& coins, int amount){
  if (amount < 0)       return -1;    // not possible
  if (amount == 0)      return 0;     // possible
  if (dp[amount] != 0)  return dp[amount];
    
  int best = INT_MAX;
  for(auto& coin : coins){
    // use a coin, then see how many more coins we need
    // with the remaining amount
    int t = coin_change_helper(coins,amount-coin);
    if (t != -1) // if it is possible, keep the min no. of coin
        best = min(best,t+1);
  }
  if (best == INT_MAX)
      return dp[amount] = -1;
  return dp[amount] = best;
}
```

Bottom-up approach:
```cpp

int coin_change(vector<int>& coins, int amount) {

  vector<int> dp(amount+1,INT_MAX-1);
  dp[0] = 0;

  for(int i = 1; i <= amount; i++){
    for(auto& coin : coins){
      if (i - coin >= 0){
        dp[i] = min(dp[i],dp[i-coin]+1);
      }
    }
  }
  if (dp[amount] == INT_MAX-1)
    return -1;
  return dp[amount];
```

