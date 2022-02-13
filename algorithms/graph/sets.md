# Union-Find

A union-find structure is a method to maintain a collection of disjoint sets with two operations:

1. `find` - to find the set containing a specific element
2. `union` - to combine two sets into one

One efficient implementation uses arrays that links an element to previous element in the set, or to itself if it is the first element in the set. Suppose that there are `n = 5` elements and they are contained in the sets `[3,2,0]` and `[4,1]`. Using the array `link`, we have

```
link[0] = 2;
link[1] = 4;
link[2] = 3;
link[3] = 3;
link[4] = 4;
```

and the elements `3` and `4` are the representatives of the two sets. Based on this structure, here is the implementation of the `find` and `union` operations:

```cpp
vector<int> link;
vector<int> size;

int main(){
  ...
  // we start off with n sets with 1 element each
  for(int i = 0; i < n; i++)
    link[i] = i;

  // keep track of the size of each set as well 
  size.resize(n,1);
}

// returns the set representative of an element x
int find(int x){
  while(link[x] != x)
    x = link[x];
  return x;
}

// check if two elements belong in the same set
bool same (int x, int y){
  return find(x) == find(y)
}

// merge two sets
void unite(int x, int y){
  int x = find(x);
  int y = find(y);
  if (size(x) > size(y){
    size(x) += size(y);
    link(y) = x;
  }
  else{
    size(y) += size(x);
    link(x) = y;
  }
}
```

## Path compression

We can rewrite the `find` function so that it updates
each node's link to its representative:
```cpp
int find(int x){
  if (x == list[x]) 
    return x;
  return list[x] = find(link[x]);
}
```

## Determining if all nodes are connected

To determine if there is only one set left, we
can have a counter for the number of sets, 
which starts at `n` (the number of nodes), 
and reduce it by one every time we perform a
unite. For example, the following code
checks if all the nodes in a graph are connected:

```cpp
// suppose the edges are contained in vector<vector<int>>
// edges

int count = list.size();
for(auto& x : edges){
  if (same(x[0],x[1])) continue;

  unite(x[0],x[1]);
  if (--count == 1)
    return true;
}
return false;

```
=======
Source: Antti
```
