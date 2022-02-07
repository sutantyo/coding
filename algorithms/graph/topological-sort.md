# Topological Sort

## Kahn's Algorithm

Algorithm:
- find all the nodes with no parents and put it 
inside a set `S`
- if `S` is empty, we have a cycle in the graph
- otherwise while there are nodes in `S`:
  - pick a node `u` and remove it from S
  - for each child `v` of `u`:
    - remove `u` from the list of parents of `v`
    - if `v` has no more parents, add `v` to `S`
- if there are still nodes with a parent, then we have
  a cycle in the graph
  - reason: if a node `v` still has at least one parent `u`,
   it means that
   we never removed `u` either, meaning it still has at least
   one parent, and so both `u` and `v` must be part of a cycle
   in the graph
```cpp
// let v be the vector of pairs 
//     {{x_0,y_0},{x_1,y_1}, ..., {x_n,y_n}}
// such that {x_i,y_i} denotes that there is a directed edge
// from y_i to x_i
string top_sort(vector<vector<int>>& v){
  string ans = "";

  map<int,set<int>> parent; // map to hold parents of x
  map<int,set<int>> child;  // map to hold children of x

  for(auto& x : v){
    parent[x[0]].insert(x[1]);
    child[x[1]].insert(x[0]);

    // we also need to add parentless nodes
    parent[x[1]];   // this adds x[1] to the map, mapped to 
                    // a set of size 0
  }

  // find all nodes with no parents
  set<int> s;   
  for(auto& x : parent){
    if (x.second.size() == 0)
      s.insert(x.first);
  }
  // if every node has at least one parent, then this graph
  // has a cycle
  if (s.size() == 0)
    return "";

  // main algorithm
  while(!s.empty()){
    int current = *(s.begin());   // takes first element
    s.erase(current);             // and remove it from the set

    ans = ans + " " + to_string(current);
    for(auto& x : child[current]){
      parent[x].erase(current);
      if (parent[x].size() == 0)
        s.insert(x);
    }
  }

  // now check if there are still nodes with parents
  for(auto& x : parent){
    if (x.second.size() > 0)
      return "";
  }
  return ans;
}
```

## DFS method

Another approach is by performing a DFS from each node with
no parents. The first few steps are similar to the previous
algorithm:
- find all the nodes with no parents and put it 
inside a set `S`
- if `S` is empty, we have a cycle in the graph
- otherwise for each node `u` in `S` start a DFS:
  - when we arrive at node for the first time, give it 
   a temporary marker,
  if we arrive at a node with a temporary marker, 
  then the graph have a cycle 
  - if we arrive at a node with a permanent marker, 
    return
  - recursively visit each children of this current node
  - before returning to the previous function call, 
    remove the temporary marker, and add a permanent marker
- if at the end there are unmarked nodes, then there is a cycle
  in the graph (for example, we can have two components in the
  graph, one has a topological sort, the other is a cycle)

```cpp
map<int,bool> perm_marker;
map<int,bool> temp_marker;
map<int,set<int>> child;
string ans = "";

void top_sort(vector<vector<int>>& v){
  // first few lines are identical to previous algorithm
  map<int,set<int>> parent;
  map<int,set<int>> child;

  for(auto& x : v){
    parent[x[0]].insert(x[1]);
    child[x[1]].insert(x[0]);
    parent[x[1]]; 
  }

  set<int> s;   
  for(auto& x : parent){
    if (x.second.size() == 0)
      s.insert(x.first);
  }
  if (s.size() == 0)
    ans = "";
 
  bool result = true;
  for(auto&x : s){
    result = result && dfs(x);
    if (result == false){
      ans = "";
      break;
    }
  }
  if (parent.size() != visited.size())
    ans = "";
}

bool dfs(int node){
  if (temp_marker.count(node))
    return false;
  if (perm_marker.count(node))
    return true;
  temp_marker[node] = true;
  bool result = true;
  for(auto& x : child[node]){
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