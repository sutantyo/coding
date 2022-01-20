# Binary Search Tree

Assume the following struct definition for the Binary Search Tree:

```cpp
struct Node{
  int data;
  Node* left;
  Node* right;
};
```

### Deleting a node

```cpp
    Node* deleteNode(Node* root, int value) {
     
        // if root is null, then there is nothing to delete
        if (root == NULL)
            return NULL;
        if (key == root->val){
            if (root->left == NULL && root->right == NULL)
                return NULL;
            if (root->left == NULL)
                return root->right;
            if (root->right == NULL)
                return root->left;
            root->val = findNextLargest(root->right);
            root->right = deleteNode(root->right,root->val);
            return root;
        }
        
        if (key < root->val){
            root->left = deleteNode(root->left,key);
            return root;
        }
        root->right = deleteNode(root->right,key);
        return root;
        
    }
    
    int findNextLargest(TreeNode* cur){
        if (cur -> left == NULL)
            return cur->val;
        else
            return findNextLargest(cur->left);
    }
```
