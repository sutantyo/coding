#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;	
};

void in_order(Node*);

int main(int argc, char* argv[]){

	Node* root = new Node{5,NULL,NULL};
	root->right = new Node{7,NULL,NULL};
	root->left = new Node{3,NULL,NULL};

	in_order(root);
	cout << endl;

}

void in_order(Node* current){
	if (current == NULL)
		return;
	in_order(current->left);
	cout << current->data << " ";
	in_order(current->right);
}
