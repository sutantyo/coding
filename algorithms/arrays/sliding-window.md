# Sliding Window

Sliding window is a general-problem solving technique when we solve the problem by looking at part of the data at a time. It is probably best explained using an example; suppose that we are given an array

`[ 8 , 5 , 3 , 8 , 2 , 6 , 9 , 11 , 2 , 3 , 7 , 11 , 9 ]`

and we are asked to find largest sum of 5 consecutive integers, which is the subarray `[ 8 , 2 , 6 , 9 , 11 ]`.

The naive method would be to add up the elements of every subarray of size 5, but this requires 4 additions, while the difference between two consecutive subarrays is just the first and last elements (e.g. the difference between `a[0..4]` and `a[1..5]` is just `a[5]-a[0]`, so instead we should do the
following:

```cpp
int a[] = {8,5,3,8,2,6,9,11,2,3,7,11,9};
for(int i = 0; i < 5; i++)
  sum += a[i];

int best = sum;
for(int i = 5; i < a.size(); i++){
  sum = sum + a[i] - a[i-5];
  if (sum > best)
    best = sum;
}
return best;
```

## Finding subarrays with the same elements

Suppose that we are given an array `a` and are asked 
to find how many subarrays in another array `b` has
the same elements.
For example, if `b = [4,2,1,3,4,3,2,1,1]`
and `a = [1,2,3,4]`, then there
are three subarrays that has the same elements as `a`
(namely `[4,2,1,3]`, `[2,1,3,4]`, and `[4,3,2,1]`).
To solve this problem, we can combine the sliding
window method with frequency count:

```cpp
// search how many subarrays of s have the same elements
// as p, return the starting indices of all such
// subarrays
vector<int> search(vector<char> s, vector<char> p) {
  if (p.length() > s.length())
      return {};

  // mapping to hold the frequency counts
  map<char,int> p_count;
  map<char,int> s_count;
  
  vector<int> ans;
  
  for(int i = 0; i < p.length(); i++){
      p_count[p[i]]++;
      s_count[s[i]]++;
  }
  if (p_count == s_count)
      ans.push_back(0);
  
  int len = s.length()-p.length()+1;
  for(int i = 1; i < len; i++){
      // remove first character from previous subarray
      // from the count, and add the count for the last
      // character

      // we also need to remove mapping to zero so the
      // map comparison works
      if (s_count[s[i-1]] == 1)
          s_count.erase(s[i-1]);
      else
          s_count[s[i-1]]--;

      s_count[s[i+p.length()-1]]++;
      if (s_count == p_count)
          ans.push_back(i);
  }
  return ans;
}
```
