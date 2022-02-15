# Insertion and Deletion

### Constructing a tree from traversal

Given the inorder traversal of a tree and its preorder or postorder 
traversal, we can construct a unique tree.
The preorder and postorder traversal tells use the order
on which the nodes should be inserted, then as we insert
the node one by one, the inorder traversal tells us whether
we have to insert to the left or to the right of the
current node.

```cpp
// to store the inorder index of each element 
map<int,int> idx; 

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.size() == 0)
        return nullptr;
    
    // 
    for(int i = 0; i < inorder.size(); i++)
        idx[inorder[i]] = i; 
    
    TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
    for(int i = postorder.size()-2; i >= 0; i--){
        insert(root,postorder[i]); 
    }
    return root;
}

void insert(TreeNode* cur, int val){
      int current = idx[cur->val];
      int i = idx[val];
      if (current > i){
          if (cur->left == nullptr){
              cur->left = new TreeNode(val);
              return;
          }
          insert(cur->left,val);
      }
      else{
          if (cur->right == nullptr){
              cur->right = new TreeNode(val);
              return;
          }
          insert(cur->right,val);
      }
}
```