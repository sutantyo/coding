# Topological Sort

### Kahn's Algorithm

Algorithm:

* find all the parentless nodes (i.e. nodes with no parents)
 and put it inside a set `S`
* if `S` is empty, we have a cycle in the graph
* otherwise while there are nodes in `S`:
  * pick a node `u` and remove it from S
  * for each child `v` of `u`:
    * remove `u` from the list of parents of `v`
    * if `v` has no more parents, add `v` to `S`
* if there are still nodes with a parent, then we have a cycle in the graph
  * reason: if a node `v` still has at least one parent `u`, it means that we never removed `u` either, meaning it still has at least one parent, and so both `u` and `v` must be part of a cycle in the graph

```cpp
// let v be the vector of pairs 
//     {{x_0,y_0},{x_1,y_1}, ..., {x_n,y_n}}
// such that {x_i,y_i} denotes that there is 
// a directed edge from y_i to x_i
string top_sort(vector<vector<int>>& v){
  string ans = "";

  map<int,set<int>> parent; // map to hold parents of x
  map<int,set<int>> adj;  // map to hold children of x

  for(auto& x : v){
    parent[x[0]].insert(x[1]);
    adj[x[1]].insert(x[0]);

    // we also need to add parentless nodes
    parent[x[1]];   // this adds x[1] to the map, mapped to 
                    // a set of size 0
  }

  // find all parentless nodes
  set<int> parentless;   
  for(auto& x : parent){
    if (x.second.size() == 0)
      parentless.insert(x.first);
  }
  // if every node has at least one parent, then this graph
  // has a cycle
  if (parentless.size() == 0)
    return "";

  // main algorithm
  while(!parentless.empty()){
    int current = *(parentless.begin());   // takes first element
    parentless.erase(current);             // and remove it from the set

    ans = ans + " " + to_string(current);
    // for each child of current node, remove this node
    // from its parents' list, then if the child has 
    // no parents, add it to parentless
    for(auto& x : adj[current]){
      parent[x].erase(current);
      if (parent[x].size() == 0)
        parentless.insert(x);
    }
  }

  // if there are still nodes with parents, there is
  // a cycle
  for(auto& x : parent){
    if (x.second.size() > 0)
      return "";
  }
  return ans;
}
```

### DFS method

Another approach is by performing a DFS from each 
parentless node (i.e. a node with no parents). 
The first few steps are similar to the previous algorithm:

* find all parentless nodes and put it inside a set `S`
* if `S` is empty, we have a cycle in the graph
* otherwise for each node `u` in `S` start a DFS:
  * when we visit a node for the first time, give it a temporary marker
  * if we visit a node that has a temporary marker,
  then the graph has a cycle because this is the second
  time we visit this node in the traversal
  * if we arrive at a node with a permanent marker, return (see below)
  * recursively visit each children of the current node
  * before returning to the previous function call, 
  remove the temporary marker, and add a permanent marker
* if after performing a DFS traversal from each parentless node
there are still nodes without a permanent marker, then
there is a cycle in the graph for the same reason
described in the previous algorithm

```cpp
map<int,bool> perm_marker;
map<int,bool> temp_marker;
map<int,set<int>> adj;
string ans = "";

string top_sort(vector<vector<int>>& v){
  // first few lines are identical to previous algorithm
  map<int,set<int>> parent;
  map<int,set<int>> adj;

  for(auto& x : v){
    parent[x[0]].insert(x[1]);
    adj[x[1]].insert(x[0]);
    parent[x[1]]; 
  }

  set<int> parentless;   
  for(auto& x : parent){
    if (x.second.size() == 0)
      parentless.insert(x.first);
  }
  if (parentless.size() == 0)
    return "";
 
  // start the DFS from each parentless node
  bool result = true;
  for(auto&x : parentless){
    result = result && dfs(x);
    if (result == false)
      return "";
  }
  // finally, if we have unvisited nodes, then there is
  // a cycle
  if (parent.size() != visited.size())
    return "";
  return ans;
}

bool dfs(int node){
  if (temp_marker.count(node))
    return false;
  if (perm_marker.count(node))
    return true;

  temp_marker[node] = true;
  bool result = true;
  for(auto& x : adj[node]){
    result = result && dfs(x);
    if (result == false)
      return false;
  }
  temp_marker[node] = false;
  perm_marker[node] = true;
  ans = to_string(current) + " " + ans;
  return result;
}

```
Relevant questions:
- [LeetCode 207 - Course Schedule](https://leetcode.com/problems/course-schedule/)


### Uniqueness

To determine if a topological sort is unique, we can check
if there is a direct edge between consecutive elements
in the topological sort. 

For example, given the topological sort `[A, B, C, D]`,
if there is no direct edge from `B` to `C`, we can swap
them around and still have a valid topological sort.

Relevant questions:
- [LeetCode 444 - Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction/)
