#include <stdio.h>
#include <stdlib.h>

int postOrder[30];
int inOrder[30];
int levelOrder[30], ptrLevel = -1;

//乖乖建树吧！

typedef struct treeNode *PtrTreeNode;
typedef struct treeNode
{
	int data;
	PtrTreeNode left;
	PtrTreeNode right;
}*Tree;

void input(int N);
Tree buildTree(int leftPost, int rightPost, int leftIn, int rightIn);
void treeTravesal(Tree T);

int main()
{
	int N;
	scanf("%d", &N);
	input(N);
	//int root = postOrder[N - 1];
	Tree T = buildTree(0, N - 1, 0, N - 1);
	treeTravesal(T);

	return 0;
}

void input(int N)
{
	for(int i = 0; i < N; i++)
		scanf("%d", &postOrder[i]);
	for(int i = 0; i < N; i++)
		scanf("%d", &inOrder[i]);
}

Tree buildTree(int leftPost, int rightPost, int leftIn, int rightIn)
{
	if(leftPost > rightPost || leftIn > rightIn)
		return NULL;

	int i;
	int leftNum, rightNum;

	PtrTreeNode root = (PtrTreeNode)malloc(sizeof(struct treeNode));
	root->data = postOrder[rightPost];

	for(i = leftIn; i <= rightIn; i++)
		if(inOrder[i] == postOrder[rightPost])
			break;

	leftNum = i - leftIn;
    rightNum = rightIn - i;

	root->left = buildTree(leftPost, leftPost + leftNum - 1, leftIn, leftIn + leftNum - 1);//Recursive
	root->right = buildTree(leftPost + leftNum, rightPost - 1, i + 1, rightIn);//Recursive

	return root;
}

void treeTravesal(Tree T)
{
	Tree queue[30];
	Tree temp;
	int front = -1, rear = -1;

	if(T == NULL)
		return;

	queue[++rear] = T;

	while(front != rear)
	{
		temp = queue[++front];
		levelOrder[++ptrLevel] = temp->data;

		if(temp->left)
			queue[++rear] = temp->left;
		if(temp->right)
			queue[++rear] = temp->right;
	}

	for(int i = 0; i < ptrLevel; i++)
		printf("%d ", levelOrder[i]);
	printf("%d\n", levelOrder[ptrLevel]);
}
