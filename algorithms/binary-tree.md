# Binary Tree

### C++ implementation

```cpp
struct node{
  int data;
  node* left;
  node* right;

  node(int data) : data(data), left(nullptr), right(nullptr) {};

}
```

### Traversal

The standard traversal of a binary tree follows the following
pattern:
```cpp
void traverse(node* current){
  if (current == nullptr)
    return;
  traverse(current->left);
  traverse(current->right);
}

Relevant questions:
- [LeetCode 104 - Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

