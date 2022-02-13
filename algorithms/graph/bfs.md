# BFS

## Determining if there is a path from a to b

```cpp
bool validPath(int n, vector<vector<int>>& edges, int a, int b) 
    
  map<int,set<int>> adj;
  map<int,bool> visited;
  for(auto& x : edges){
      adj[x[0]].insert(x[1]);
      adj[x[1]].insert(x[0]);
  }

  queue<int> q;
  q.push(a);
  
  while(!q.empty()){
      int cur = q.front();
      if (cur == b)
          return true;
      q.pop();
      visited[cur] = true;
      for(auto& x : adj[cur]){
          if (!visited[x])
              q.push(x);
      }
  }
  return false;
}
```