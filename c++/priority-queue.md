# Priority Queue

C++ `priority_queue` is implemented as a max-heap and 
can perform comparison on basic data types 
(including `pair` objects). 
See the next example to see how the ordering is done 
with `pair` objects.

### Basic operations:

```cpp
// pq of pair<int,pair<char,int>>

priority_queue< pair<int,pair<char,int>> > pq;
pq.push(make_pair(3,make_pair('c',1)));
// alternatively: pq.emplace(3,make_pair('c',1));
pq.push(make_pair(5,make_pair('a',2)));
pq.push(make_pair(3,make_pair('a',4)));
pq.push(make_pair(5,make_pair('b',4)));
pq.push(make_pair(5,make_pair('b',3)));
pq.push(make_pair(5,make_pair('b',3))); // duplicates are fine

while(!pq.empty()){
  cout << pq.top().first << " " << pq.top().second.first << " ";
  cout << pq.top().second.second << endl;
  pq.pop();
}

/* Output:
    5 b 4
    5 b 3
    5 b 3
    5 a 2
    3 c 1
    3 a 4
*/
```

If we instead want a min-heap of basic data types, then the simplest approach is to use `std::greater`, which requires us to use the parameterised constructor. The second parameter is the container we use to hold the priority queue, which is often a vector.

```cpp
typedef pair<int,pair<char,int>> data
...
priority_queue< data,vector<data>,greater<data> > pq;
pq.push(make_pair(3,make_pair('c',1)));
pq.push(make_pair(5,make_pair('a',2)));
pq.push(make_pair(3,make_pair('a',4)));
pq.push(make_pair(5,make_pair('b',4)));
pq.push(make_pair(5,make_pair('b',3)));
pq.push(make_pair(5,make_pair('b',3))); 
```

should now print out

```cpp
/* Output:
    3 a 4
    3 c 1
    5 a 2
    5 b 3
    5 b 3
    5 b 4
*/
```

We can also have `priority_queue<vector<int>>` which can be useful at times. The vectors are sorted lexicographically.

```
{7,8}
{1,2,3,4,5}
{1,2,3}
```

If we'd like to have a `priority_queue` of `vector<int>*` instead, then we need to use a custom comparator, which is discussed in the next section.

### Custom comparator

The syntax for declaring a custom comparator is a bit clunky (maybe there is a better method?): we need to create a lambda object, then pass it as a `decltype` as the third parameter. Here is the example of sorting an array of `vector<int>*` in increasing order:

```cpp
auto comp = [&](vector<int>* a, vector<int>* b){
  return *a > *b; // leveraging C++ vector comparison
}
priority_queue<vector<int>*,
               vector<vector<int>*>,
               decltype(comp)> pq(comp);
```

### Custom object

It can be simpler to have a `priority_queue` of custom objects (class/struct) because all we need is the `boolean operator<` function, for example:

```cpp
struct data{
  int a;
  int b;
  bool operator< (const data& other) const{
    return (a+b) < (other.a + other.b);
  }
}
```
