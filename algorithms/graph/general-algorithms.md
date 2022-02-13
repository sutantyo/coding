# General Algorithms

## Cloning a graph

Suppose the graph is implemented as follows:
```cpp
class Node{
  int val;
  vector<Node*> neighbours;

  Node() : val(0);
  Node(int val, vector<Node*> v) : val(val), neighbours(v){};
}
```
then to clone the graph (deep copy), 
we can use DFS, keeping track
of the newly created nodes as follows:
```cpp

map<int,bool> marked;    // to mark nodes as visited 
map<int,Node*> new_addr; // to store the new nodes

Node* clone_graph(Node* node) {
  if (node == nullptr)
    return nullptr;
  if (marked[node->val])
    return new_addr[node->val];
  marked[node->val] = true;
    
  Node* root = new Node(node->val,node->neighbors);
  new_addr[node->val] = root;
  
  for(int i = 0; i < root->neighbors.size(); i++){
      root->neighbors[i] = clone_graph(root->neighbors[i]);
  }
  return root;
}
```

