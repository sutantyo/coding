# DFS

## Determining if there is a path from a to b


```cpp
bool dfs(int cur, int target, map<int,set<int>>& adj, map<int,bool>& visited){
  if (cur == target)
      return true;
  
  visited[cur] = true;
  
  bool ans = false;
  for(auto& x : adj[cur]){
      if (!visited[x]){
          ans = ans || dfs(x, target, adj, visited);
      }
  } 
  return ans;
}
```

