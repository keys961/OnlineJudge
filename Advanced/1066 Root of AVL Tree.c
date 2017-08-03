#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *AvlTree;
typedef struct TreeNode *Node;
struct TreeNode
{
	int element;
	Node left;
	Node right;
	int height;
};

int getHeight(Node node);
int getMax(int a, int b);
Node insert(int X, AvlTree T);

Node leftRotate(Node node);
Node rightRotate(Node node);

int main(int argc, char const *argv[])
{
	int N;
	int X;
	AvlTree T = NULL;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		scanf("%d", &X);
		T = insert(X, T);
	}

	printf("%d\n", T->element);
	return 0;
}

int getHeight(Node node)
{
	if(node == NULL)
		return -1;
	return getMax(getHeight(node->left), getHeight(node->right)) + 1;
}

int getMax(int a, int b)
{
	return a > b ? a : b;
}

Node insert(int X, AvlTree T)
{
	if(T == NULL)
	{
		Node newNode = (Node)malloc(sizeof(struct TreeNode));
		newNode->element = X;
		newNode->left = newNode->right = NULL;
		newNode->height = 0;
		return newNode;
	}

	if(X < T->element)
	{
		T->left = insert(X, T->left);
		if(getHeight(T->left) - getHeight(T->right) == 2)
		{
			if(X < T->left->element)//Rotate right
				T = rightRotate(T);
			else
			{
				T->left = leftRotate(T->left);
				T = rightRotate(T);
			}
		}
		T->height = getHeight(T);
	}
	else if(X > T->element)
	{
		T->right = insert(X, T->right);
		if(getHeight(T->right) - getHeight(T->left) == 2)
		{
			if(X > T->right->element)//Rotate left
				T = leftRotate(T);
			else
			{
				T->right = rightRotate(T->right);
				T = leftRotate(T);
			}
		}
		T->height = getHeight(T);
	}
	else{}//Do nothing
	return T;
}

Node leftRotate(Node node)
{
	Node child = node->right;
	node->right = child->left;
	child->left = node;

	return child;
}

Node rightRotate(Node node)
{
	Node child = node->left;
	node->left = child->right;
	child->right = node;

	return child;
}
