# Traversal

### C++ implementation

```cpp
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {};

}
```

### DFS traversal

The standard traversal of a binary tree uses DFS with the
following pattern:
```cpp
void traverse(TreeNode* current){
  if (current == nullptr)
    return;
  traverse(current->left);
  traverse(current->right);
}
```

Traversal questions:
- [LeetCode 94 - Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
- [LeetCode 144 - Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)
- [LeetCode 145 - Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)
- [LeetCode 589 - N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)
- [LeetCode 590 - N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)

Questions using simple traversal:
- [LeetCode 104 - Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [LeetCode 112 - Path Sum](https://leetcode.com/problems/path-sum)
- [LeetCode 113 - Path Sum II](https://leetcode.com/problems/path-sum-ii)
- [LeetCode 437 - Path Sum III](https://leetcode.com/problems/path-sum-iii) - extension of [LeetCode 560 - Subarray Sums Equals K](
  https://leetcode.com/problems/subarray-sum-equals-k/
)

### BFS traversal

We can use BFS to do level-order traversal. The following code
stores the nodes on each level in a double array.
The key thing to do is to have a for loop that pops the
correct amount of nodes in the same level from the queue.
```cpp
    vector<vector<int>> level_traversal(TreeNode* root) {
        
        vector<vector<int>> answer;
        if (root == nullptr)
            return answer;
        
        queue<TreeNode*> q; 
        q.push(root);
        
        while(!q.empty()){
            
            vector<int> current;
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* cur = q.front();
                q.pop();
                current.push_back(cur->val);
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            answer.push_back(current);
        }
        return answer;
    }
```
While BFS should be the standard approach for doing level-order traversal,
if we need to store the nodes on each level, using DFS that keeps
track of the current level is probably easier to write.

Relevant questions:
- [LeetCode 102 - Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
- [LeetCode 116 - Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)
- [LeetCode 117 - Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

### Symmetric trees

If a binary tree is symmetrical, its left subtree must be a mirror image
of its right subtree.
```cpp
bool isSymmetric(TreeNode* root) {
    return is_mirror(root,root);
}

bool is_mirror(TreeNode* t1, TreeNode* t2){
    if (t1 == nullptr && t2 == nullptr)
        return true;
    if (t1 == nullptr || t2 == nullptr)
        return false;
    return (t1->val == t2->val) && is_mirror(t1->left,t2->right) && is_mirror(t1->right,t2->left);
}
```
Relevant questions:
- [LeetCode 101 - Symmetric Tree](https://leetcode.com/problems/symmetric-tree)

### Number of univalue subtrees

The following code works out the number of subtrees that has
the same value in all its nodes. 

```cpp
int count = 0;

int countUnivalSubtrees(TreeNode* root) {
    traverse(root);
    return count;
}

// return true if cur is a root of a unival tree
bool traverse(TreeNode* cur){
    if (cur == nullptr)
        return true;
    if (cur->left == nullptr && cur->right == nullptr){
        count++;
        return true;
    }
    
    // check left and right subtrees
    bool left = traverse(cur->left);
    bool right = traverse(cur->right);
    
    // return false if one of them is not a unival tree
    if (!left || !right)
        return false;
  
    // if both subtrees are unival, then see if we have 
    // the same value with both subtrees
    bool same = true;
    if (cur->left != nullptr)
        same = (cur->val == cur->left->val) && same;
    if (cur->right != nullptr)
        same = (cur->val == cur->right->val) && same;
    
    if (same){
        count++;
        return true;
    }
    return false;
  }
```
Relevant questions:
- [LeetCode 250 - Count Univalue Subtrees](https://leetcode.com/problems/count-univalue-subtrees/)

### Finding lowest common ancestor

Suppose we want to find the common ancestor of two nodes `a` and `b`
in a tree. 
A node can be a descendant to itself, so if `a` and `b` are the only
two nodes in the tree, then whichever is the root is the lowest
common ancestor of the two.

To find the lowest common ancestor once, we can traverse the tree
until we find either `a` or `b`, and start returning true when
we do. The lowest common ancestor is the node where both children
returns true OR if it contains either `a` or `b` and one of its
children returns true.

```cpp
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        traverse(root,p,q,ans);
        return ans;
    }
    
    bool traverse(TreeNode* cur, TreeNode* p, TreeNode* q, TreeNode* &ans){
      // ans holds the lowest common ancestor
      if (ans != nullptr)
          return false;
      if (cur == nullptr)
          return false;
      bool found = ((cur == p) || (cur == q));
      bool left = traverse(cur->left,p,q,ans);
      bool right = traverse(cur->right,p,q,ans);

      // in this version, once we found the lowest common ancestor,
      // we store it in ans
      if ((found && left) || (found && right) || (left && right))
          ans = cur;
      return found || left || right;
    }
```
However, if we were to do it many times, then we can do the following
preprocessing (the Euler tour of a tree) where we note down   
the node and its height every time we walk through it. 
```cpp
vector<pair<node*,int>> tour; 

void traverse(TreeNode* cur, int height){
    if (cur == nullptr)
        return;
    tour.push_back({cur,height});
    traverse(cur->left,height+1);
    tour.push_back({cur,height});
    traverse(cur->right,height+1);
    tour.push_back({cur,height});
}
```
The lowest common ancestor of `a` and `b` is the node with the least
height in this tour.
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  // preprocess
  traverse(root,0);    
  
  TreeNode* ans;
  int in_range = false;
  int end, min;
  for(int i = 0; i < tour.size(); i++){
    if (in_range){
        if (tour[i].second < min){
            min = tour[i].second;
            ans = tour[i].first;
        }
        if (tour[i].first->val == end)
            break;
    } 
    if ((tour[i].first->val == p->val || tour[i].first->val == q->val) && !in_range){
        end = (tour[i].first->val == p->val) ? q->val : p->val;
        in_range = true;
        ans = tour[i].first;
        min = tour[i].second;
    }
  }
  return ans;
}
```
We can also use this to find the distance between any two nodes
in a binary tree, since this is equal to the sum of the distances
between
the nodes to their common ancestor.

Relevant questions:
- [LeetCode 236 - Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
- [LeetCode 1740 - Find Distance in a Binary Tree](https://leetcode.com/problems/find-distance-in-a-binary-tree/)



