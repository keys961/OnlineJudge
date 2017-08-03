#include <stdio.h>
#include <stdlib.h>

//Build trees, don't think about tricks

typedef struct treeNode *TreeNode;
struct treeNode
{
	int data;
	TreeNode left;
	TreeNode right;
};

int pOrder[1000];

TreeNode input(int N);
int preOrder(TreeNode tree);
int preOrderMirror(TreeNode tree);
int isBinarySearchTree(TreeNode tree);
void postOrder(TreeNode tree, int N);
void postOrderMirror(TreeNode tree, int N);

int main()
{
	int N, value;
	scanf("%d", &N);
	TreeNode tree = input(N);

	if((value = isBinarySearchTree(tree)) == 1)
	{
		printf("YES\n");
		postOrder(tree, N);
	}
	else if(value == 2)
    {
        printf("YES\n");
		postOrderMirror(tree, N);
    }
	else
		printf("NO\n");


	return 0;
}

TreeNode input(int N)
{
	if(N == 0)
		return NULL;

	TreeNode head = (TreeNode)malloc(sizeof(struct treeNode));
	head->left = NULL;
	head->right = NULL;
	TreeNode cursor, new;

	for(int i = 0; i < N; i++)
	{
		cursor = head;
		scanf("%d", &pOrder[i]);
		if(i == 0)
			cursor->data = pOrder[i];
		else
		{
			while(pOrder[i] < cursor->data && cursor->left
            || pOrder[i] >= cursor->data && cursor->right)
            {
                if(pOrder[i] < cursor->data)
                    cursor = cursor->left;
                else
                    cursor = cursor->right;
            }

			new = (TreeNode)malloc(sizeof(struct treeNode));
			new->data = pOrder[i];
			new->left = new->right = NULL;

			if(pOrder[i] < cursor->data)
				cursor->left = new;
			else
				cursor->right = new;
		}
	}
	return head;
}

int isBinarySearchTree(TreeNode tree)
{
	if(preOrder(tree) == 1)
		return 1;
	else
		if(preOrderMirror(tree) == 1)
			return 2;
		else
			return 0;
}

int preOrder(TreeNode tree)
{
	static int index = -1;
	index++;
	static int flag = 1;
	if(tree->data != pOrder[index])
		return flag = 0;
	else
	{
		//index++;
		if(tree->left)
			preOrder(tree->left);
		if(tree->right)
			preOrder(tree->right);
        return flag;
	}
}

int preOrderMirror(TreeNode tree)
{
	static int index = -1;
	static int flag = 1;
	index++;
	if(tree->data != pOrder[index])
		return flag = 0;
	else
	{
		if(tree->right)
			preOrderMirror(tree->right);
		if(tree->left)
			preOrderMirror(tree->left);
        return flag;
	}

}

void postOrder(TreeNode tree, int N)
{
	static int count = 0;

	if(tree->left)
		postOrder(tree->left, N);
	if(tree->right)
		postOrder(tree->right, N);

	count++;
	if(count == N)
		printf("%d\n", tree->data);
	else
		printf("%d ", tree->data);
}

void postOrderMirror(TreeNode tree, int N)
{
	static int count = 0;

	if(tree->right)
		postOrderMirror(tree->right, N);
	if(tree->left)
		postOrderMirror(tree->left, N);

	count++;
	if(count == N)
		printf("%d\n", tree->data);
	else
		printf("%d ", tree->data);
}
