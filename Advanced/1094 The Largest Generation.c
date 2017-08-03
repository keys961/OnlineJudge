#include <stdio.h>
#include <stdlib.h>

int tree[101][100] = {0,}; //AdjList
int visited[101] = {0,};

int input(int N, int M);
int* getLargest(int root);

int main()
{
	int N, M, root;
	int* largest = NULL; //[0]: number; [1]: generation
	scanf("%d %d", &N, &M);
	root = input(N, M);

	largest = getLargest(root);

	printf("%d %d\n", largest[0], largest[1]);
	return 0;
}

int input(int N, int M)
{
	int r;
	int root[101] = {0,};
	int parent, K;
	for(int i = 0; i < M; i++)
	{
		scanf("%d %d", &parent, &K);
		for(int j = 0; j < K; j++)
		{
			scanf("%d", &tree[parent][j]);
			root[tree[parent][j]] = 1;
		}
	}

	for(r = 1; r <= N; r++)
		if(root[r] == 0)
			break;
	return r;
}

int* getLargest(int root)
{
	int* largest = (int*)malloc(sizeof(int) * 2);
	int last = root;
	int temp;
	int generation = 1, maxGeneration = -1;
	int number = 0, maxNumber = 0;
	int queue[100]; int front = -1, rear = -1;

	queue[++rear] = root;
	visited[root] = 1;

	while(front != rear)
	{
		temp = queue[++front];
		number++;
		for(int i = 0; tree[temp][i]; i++)
		{
			if(visited[tree[temp][i]] == 0)
			{
				queue[++rear] = tree[temp][i];
				visited[tree[temp][i]] = 1;
			}
		}
		if(temp == last) //Compare
		{
			if(number > maxNumber)
			{
				maxNumber = number;
				maxGeneration = generation;
			}
			number = 0;
			generation++;
			last = queue[rear];
		}
	}

	largest[0] = maxNumber;
	largest[1] = maxGeneration;
	return largest;
}
