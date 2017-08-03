#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*another algorithm: know pre and in to get post*/
typedef struct stackNode
{
	struct treeNode* elements[30];
	int top;
}*Stack;

typedef struct treeNode
{
	int element;
	struct treeNode* left;
	struct treeNode* right;
}*Tree, *Position;

Stack CreateStack();
int IsEmpty(Stack st);
void Push(Position element, Stack st);
Position Pop(Stack st);
int IsEmpty(Stack st);
void TreeTraversal(Tree T);

int amount;
int count = 0; //global variables QAQ

int main()
{
	char command[5];
	int N;
	int data;
	int isPopped = 0, isFirst = 1;
	int count = 0;
	Tree T = NULL;
	Position node, temp = NULL;
	Stack st = CreateStack();

	scanf("%d", &N);
	amount = N;
	/*Build the binary tree*/
	while(count < N )
	{
		scanf("%s", command);
		if(!strcmp("Push",command)) //push
		{
			scanf("%d", &data);
			node = (Position)malloc(sizeof(struct treeNode));
			node->element = data;
			node->left = node->right = NULL;
			Push(node, st);
			if(isFirst)
			{
				T = node;
				isFirst = 0; //get the head node of the tree
			}
			if(temp && isPopped == 0)
			{
				temp->left = node;
				temp = node;
			}
			else if(temp && isPopped)
			{
				temp->right = node;
				temp = node;
				isPopped = 0;
			}
			else if(temp == NULL)
				temp = node;
		}
		else //pop
		{
			temp = Pop(st);
			isPopped = 1;
			count ++;
		}
	}
	TreeTraversal(T);
	return 0;
}

Stack CreateStack()
{
	Stack st = (Stack)malloc(sizeof(struct stackNode));
	st->top = -1;
	return st;
}

void Push(Position element, Stack st)
{
	st->top++;
	st->elements[st->top] = element;
}

int IsEmpty(Stack st)
{
	if (st->top == -1)
		return 1;
	return 0;
}

Position Pop(Stack st)
{
	Position element;
	if (!IsEmpty(st))
	{
		element = st->elements[st->top];
		st->top--;
		return element;
	}
	return NULL;
}

void TreeTraversal(Tree T)
{
	//static int times = 0;
	if(T == NULL);
	else
	{
		TreeTraversal(T->left);
		TreeTraversal(T->right);
		if(count < amount - 1)
		{
			printf("%d ", T->element);
			count ++;
		}
		else //judge whether space needs inputting 
			printf("%d\n", T->element);
	}
}


//Another solve:
//pre[] in[] post[] are global 
//preLocation: first index of pre[]
//inLocation: first index of in[]
//postLocation: first index of post[]
//n: length of an array
void Solve(int preLocation, int inLocation, int postLocation, int n)
{
	int i;
	int nL, nR;
	int root;
	if(n == 0)
		return;
	if(n == 1)
	{
		post[postLocation] = pre[preLocation];
		return;
	}
	root = pre[preLocation];
	post[n-1] = root;
	for(i = 0; i < n; i++)
	{
		if(in[inLocation + i] == root);
		break;
	}
	nL = i; nR = n - nL - 1;
	//recursion
	Solve(preLocation + 1, inLocation, postLocation, nL); //left tree
	Solve(preLocation + nL + 1, inLocation + nL + 1, postLocation + nL, nR);//right tree
}