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

        // if the root contains the value we need to delete, this is
        // where we have to do the most work
        if (key == root->data){
            
            // these are the simpler cases when one of the children
            // is null, because we can just set root to be the non-null 
            // child (or just set root to null if both children are null)
            if (root->left == NULL && root->right == NULL)
                return NULL;
            if (root->left == NULL)
                return root->right;
            if (root->right == NULL)
                return root->left;

            // otherwise, we have to find the next largest value in the BST
            // that is on the right side of the tree and put that value into 
            // root (figuratively, we're swapping the root node with the next largest node)
            root->data = findNextLargest(root->right);

            // next, we need to delete the node with that value
            root->right = deleteNode(root->right,root->data);
            return root;
        }
        
        // if the value in the root node is not the one that we have to delete,
        // then we have to go find the value in the tree:
        if (key < root->data){
            root->left = deleteNode(root->left,key);
            return root;
        }
        root->right = deleteNode(root->right,key);
        return root;
        
    }
    
    int findNextLargest(Node* cur){
        // next largest element should have no left child, so, just keep going left
        // until we can't
        if (cur -> left == NULL)
            return cur->data;
        else
            return findNextLargest(cur->left);
    }
```
