# Binary Search Tree

### C++ implementation

```cpp
struct node{
  int data;
  node* left;
  node* right;

  node(int data) : data(data), left(nullptr), right(nullptr) {};
};
```

### Converting a sorted array to a binary search tree

**Algorithm**: choose the middle element of the array as the root
node, then recursively build the left and right subtrees using
the left and right subarrays (we pass the starting and
end indices of the subarrays).

```cpp
node* create_bst_from_sorted_array(vector<int> &nums){
    return create_tree(nums,0,nums.size()-1);
}

node* create_tree(vector<int> &nums, int start, int end){
    if (start > end)
        return nullptr;
    int mid = (start+end)/2;
    node* cur = new node(nums[mid]);
    cur->left = create_tree(nums,start,mid-1);
    cur->right = create_tree(nums,mid+1,end);
    
    return cur;
}
```
Relevant questions:
- [https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/)


### Deleting a node

It is easy to delete a node with no children or with only one 
child, since we just replace the deleted node with null or
its child. However, if the node to be deleted has two children,
then we need to replace it with its descendant, either
the next largest or the next smallest value. In the following code,
we choose the next largest element.

```cpp
node* delete_node(node* cur, int value) {
     
    // if root is null, then there is nothing to delete
    if (root == NULL)
        return NULL;

    // if the root contains the value we need to delete
    if (key == root->data){
        
        // simpler cases (0 or 1 children)
        if (root->left == NULL && root->right == NULL)
            return NULL;
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;

        // otherwise, find the next largest value
        // and set it to be this node's value
        root->data = find_next_largest(root->right);

        // then delete the node with that value 
        root->right = delete_node(root->right,root->data);
        return root;
    }

    // otherwise, traverse the tree to find the node with the
    // value we have to delete
    if (key < root->data){
        root->left = delete_node(root->left,key);
        return root;
    }
    root->right = delete_node(root->right,key);
    return root;
    
    }

int find_next_largest(node* cur){
    // the next largest element in a BST is the leftmost node
    if (cur->left == NULL)
        return cur->data;
    else
        return find_next_largest(cur->left);
}
```
