#include <stdio.h>
#include <stdlib.h>

int Tree[100][100] = {0,}; //AdjList for tree, root is 01

void Initialize();
void Input();
void CountLeaves();

int main()
{
	int N, M;
	int father, child, childNum;
	scanf("%d", &N);
	Initialize();
	scanf("%d", &M);
	for(int i = 0; i < M; i++)
	{
		scanf("%d %d", &father, &childNum);
		for(int j = 0; j < childNum; j++)
		{
			scanf("%d", &child);
			Tree[father][j] = child;
		}
	}
	CountLeaves();
	return 0;
}

void Initialize()
{
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			Tree[i][j] = 0;
}

void CountLeaves()
{
	int Queue[100] = {0,};
	int count = 0;
	int i;
	int temp;
	int last = 01;
	int front = -1, rear = -1;
	Queue[++rear] = 01; //Push root;
	while(front != rear)
	{
		temp = Queue[++front];
		for(i = 0; i < 100; i++)
		{
			if(Tree[temp][i] != 0)
				Queue[++rear] = Tree[temp][i];
			else
				break;
		}
		if(i == 0) //Current node is a leaf
			count++;
		if(temp == last) //Need print the result
		{
			if(front != rear)
			{
				last = Queue[rear]; //Move the last ptr to the end of the next level
				printf("%d ", count);
				count = 0;
			}
			else
				printf("%d\n", count);
		}
	}
}