#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int el;
	struct node *left, *right;
}node;

node *root = NULL;

node *insert(node *root, int val){
	if(root == NULL){
		node *n = (node *)malloc(sizeof(node));
		n->el = val;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	if(val < root->el){
		root->left = insert(root->left, val);
	}else if(val > root->el){
		root->right = insert(root->right, val);
	}
	return root;
}

void inorder(node *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ->", root->el);
		inorder(root->right);
	}
}

node *search(node *root, int key){
	if(root == NULL || root->el == key){
		return root;
	}else if(root->el < key){
		return search(root->right, key);
	}else{
		return search(root->left, key);
	}
}

void searchfunc(node *root, int key){
	node *r = search(root, key);
	if(r != NULL){
		printf("\nKey %d found in bst\n", key);
	}
	else{
		printf("\nKey %d not found in bst\n", key);
	}
}

int main(){
	int key = 5;
	root = insert(root, 89);
	root = insert(root, 78);
	root = insert(root, 55);
	root = insert(root, 31);
	inorder(root);
	searchfunc(root, key);
	root = insert(root, 5);
	inorder(root);
	searchfunc(root, key);
	return 0;
	
}
