#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* left;
  node* right;

  node(int data) : data(data), left(nullptr), right(nullptr) {};
};

void in_order(node*);

int main(int argc, char* argv[]){

	node* root = new node(5);
	root->right = new node(7);
	root->left = new node(3);

	in_order(root);	cout << endl;
}

void in_order(node* current){
	if (current == nullptr)
		return;
	in_order(current->left);
	cout << current->data << " ";
	in_order(current->right);
}
