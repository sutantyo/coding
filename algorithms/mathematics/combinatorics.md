# Combinatorics

## Stars and Bars

To avoid overflow while computing `(m+n)!/(m!*n!)`, 
we can do the following:
```cpp
  long long sum = m+n;
  
  long long a = max(m,n);
  long long b = min(m,n);
  
  long long prod = 1;
  for(long i = sum, j = b; i > a || j >= 1; i--, j--){
      if (i <= a) i = 1;
      if (j < 1) j = 1;

      prod = prod * i; 

      if (prod % j == 0)
          prod = prod / j;
      else
          j++;
      if (i == a && j == 1) break;
  } 
  return prod;
