#include <iostream>
#include<queue>
using namespace std;

struct tnode{
	int da;
	tnode* left;
	tnode* right;
};

int minnode(tnode* node){
	if(node->left == NULL)
		return node->da;
	else
		return minnode(node->left);
}

void deleteit(tnode* node, int abc){
	if(node == NULL)
		return;
	if(node->da == abc){
        if(node->left == NULL)
        	node = node->right;
        else if(node->right == NULL)
        	node = node->left;
        else{
        	node->da = minnode(node->right);
        	int ja = node->da;
        	if(node->right->da = node->da)
        		node->right = node->right->right;
        	else{
        		node = node->right;
        		while(node->left->left != NULL)
        			node = node->left;
        		node->left = node->left->right;
        	}

        }
	}
	else if(abc < node->da)
		deleteit(node->left, abc);
	else
		deleteit(node->right, abc);
}

tnode* gta5(int data){
	tnode* newnode = new tnode;
	newnode->da = data;
	return newnode;
}

tnode* insert(tnode* root, int data){
	if(root == NULL)
		root = gta5(data);
	else{
		if(data <= root->da)
			root->left = insert(root->left, data);
		else
			root->right = insert(root->right, data);
	}
	return root;
}

void LevelOrder(tnode *root) {
	if(root == NULL) return;
	queue<tnode*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		tnode* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->da<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}

int main(int argc, char const *argv[])
{
    tnode* fff;
	fff = insert(fff, 12);
	fff = insert(fff, 5);
	fff = insert(fff, 3);
	fff = insert(fff, 1);
	fff = insert(fff, 1);
	fff = insert(fff, 7);
	fff = insert(fff, 9);
	fff = insert(fff, 8);
	fff = insert(fff, 11);
	fff = insert(fff, 15);
	fff = insert(fff, 13);
	fff = insert(fff, 14);
	fff = insert(fff, 17);
	fff = insert(fff, 20);
	fff = insert(fff, 20);
	fff = insert(fff, 16);
	deleteit(fff, 15);
	LevelOrder(fff);
	return 0;
}