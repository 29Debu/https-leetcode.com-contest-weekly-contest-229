#include <iostream>
using namespace std;

struct tnode{
	int da;
	tnode *left;
	tnode *right;
};

tnode* gtnode(int tata){
	tnode* newnode = new tnode();
    newnode->da = tata;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int height(tnode* root){
	if(root == NULL)
		return 0;
	int ll = 1 + height(root->left);
	int rr = 1 + height(root->right);
	return max(ll, rr);
}

void printCurrentLevel(tnode* root, int you){
	if (root == NULL)
        return;
	if(you == 0)
		cout<<root->da;
	else{
		printCurrentLevel(root->left, you-1);
		printCurrentLevel(root->right, you-1);
	}
}

void levelorderprint(tnode* root){
	int jay = height(root);
	for (int i = 0; i < jay; ++i)
		printCurrentLevel(root, i);
}

tnode* insert(tnode* root, int data){
	if(root == NULL){
		root = gtnode(data);
	}
	else{
		if (data <= root->da)
		{
			root = insert(root->left, data);
		}
		else
			root = insert(root->right, data);
	}
	return root;
}

int main()
{
	tnode* fff;
	fff = insert(fff, 10);
	fff = insert(fff, 7);
	fff = insert(fff, 15);
	fff = insert(fff, 11);
	fff = insert(fff, 1);
	fff = insert(fff, 19);
	fff = insert(fff, 9);
	levelorderprint(fff);
	return 0;
}