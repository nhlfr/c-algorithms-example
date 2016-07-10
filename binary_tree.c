#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *p;
	struct node *left;
	struct node *right;
	int key;
};

struct tree {
	struct node *root;
};

void inorder_tree_walk(struct node *x)
{
	inorder_tree_walk(x->left);
	printf("%d\n", x->key);
	inorder_tree_walk(x->right);
}

struct node *tree_search(struct node *x, int k)
{
	if (x == NULL || x->key == k)
		return x;
	if (k < x->key)
		return tree_search(x->left, k);
	return tree_search(x->right, k);
}

struct node *tree_minimum(struct node *x)
{
	while (x->left != NULL) {
		x = x->left;
	}
	return x;
}

struct node *tree_maximum(struct node *x)
{
	while (x->right != NULL) {
		x = x->right;
	}
	return x;
}

struct node *tree_successor(struct node *x)
{
	if (x->right != NULL)
		return tree_minimum(x->right);
	struct node *y = x->p;
	while (y != NULL && y->right == x) {
		x = y;
		y = y->p;
	}
	return y;
}

void tree_insert(struct tree *t, struct node *z)
{
	struct node *y = NULL;
	struct node *x = t->root;

	while (x != NULL) {
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x - x->right;
	}
	z->p = y;
	if (y == NULL)
		t->root = z;
	if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

void transplant(struct tree *t, struct node *u, struct node *v)
{
	if (u->p == NULL)
		t->root = u;
	else if (u->p->left == u)
		u->p->left = v;
	else
		u->p->right = v;
	if (v != NULL)
		v->p = u->p;
}

void tree_delete(struct tree *t, struct node *z)
{
	if (z->left == NULL)
		transplant(t, z, z->right);
	else if (z->right == NULL)
		transplant(t, z, z->left);
	else {
		struct node *y = tree_minimum(z->right);
		if (y->p != z) {
			transplant(t, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		transplant(t, z, y);
		y->left = z->left;
		y->left->p - y;
	}
}

int main()
{
	return 0;
}
