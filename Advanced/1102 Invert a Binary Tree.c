#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
	int left;
	int right;
}TreeNode;
typedef TreeNode *Tree;

int input(Tree binaryTree, int N);
void levelOrder(Tree binaryTree, int N, int root);
void inOrder(Tree binaryTree, int N, int root);

int main()
{
	Tree binaryTree = NULL;
	int N, root;
	scanf("%d", &N);
    getchar();
	binaryTree = (Tree)malloc(sizeof(TreeNode) * N);
	root = input(binaryTree, N);

	levelOrder(binaryTree, N, root);
	inOrder(binaryTree, N, root);

	return 0;
}

int input(Tree binaryTree, int N)
{
	char left, right;
	int root;
	int visited[10] = {0, };
	for(int i = 0; i < N; i++)
	{
		scanf("%c", &left);
		getchar();
		scanf("%c", &right);
		getchar();
		binaryTree[i].left = (right == '-') ? -1 : right - '0';
		if(binaryTree[i].left != -1)
			visited[binaryTree[i].left] = 1;
		binaryTree[i].right = (left == '-') ? -1 : left - '0';
		if(binaryTree[i].right != -1)
			visited[binaryTree[i].right] = 1;
	}

	for(root = 0; root < N; root++)
		if(visited[root] == 0)
			break;

	return root;
}

void levelOrder(Tree binaryTree, int N, int root)
{
	int Queue[20];
	int node;
	int front = -1, rear = -1;
	int count = 0;
	Queue[++rear] = root;

	while(front != rear)
	{
		node = Queue[++front];
		if(count == N - 1)
			printf("%d\n", node);
		else
		{
			printf("%d ", node);
			count++;
		}

		if(binaryTree[node].left != -1)
			Queue[++rear] = binaryTree[node].left;
		if(binaryTree[node].right != -1)
			Queue[++rear] = binaryTree[node].right;
	}
}

void inOrder(Tree binaryTree, int N, int root)
{
	static int count = 0;

	if(binaryTree[root].left != -1)
		inOrder(binaryTree, N, binaryTree[root].left);

	if(count == N - 1)
		printf("%d\n", root);
	else
	{
		printf("%d ", root);
		count++;
	}

	if(binaryTree[root].right != -1)
		inOrder(binaryTree, N, binaryTree[root].right);
}
