#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graphNode *GNode;
struct graphNode
{
	int index;
	GNode next;
};

typedef struct graph
{
	GNode *adjList;
	int capacity;
}*Graph;

int visited[100000] = {0,};
int leaf[100000] = {0,};

Graph createMap(int N);
double getTotalSale(Graph map, double initPrice, double incrementRate, int N);

int main()
{
	int N;
	double initPrice, incrementRate;
	scanf("%d %lf %lf", &N, &initPrice, &incrementRate);
	Graph map = createMap(N);

	printf("%.1f\n", getTotalSale(map, initPrice, incrementRate, N));
	return 0;
}

Graph createMap(int N)
{
	int K, id;

	Graph map = (Graph)malloc(sizeof(struct graph));
	map->capacity = N;
	map->adjList = (GNode*)malloc(sizeof(GNode) * N);

	GNode src, temp, newNode;

	for(int i = 0; i < N; i++)
    {
        map->adjList[i] = (GNode)malloc(sizeof(struct graphNode));
        map->adjList[i]->index = i;
        map->adjList[i]->next = NULL;
    }


	for(int i = 0; i < N; i++)
	{

		scanf("%d", &K);

		if(K == 0)
		{
			scanf("%d", &leaf[i]);
			//leaf[i] = id;
			continue;
		}

		for(int j = 0; j < K; j++)
		{
		    src = map->adjList[i];
            temp = src->next;
			scanf("%d", &id);
			newNode = (GNode)malloc(sizeof(struct graphNode));
			src->next = newNode;
			newNode->next = temp;
			newNode->index = id;
		}
	}

	return map;
}

double getTotalSale(Graph map, double initPrice, double incrementRate, int N)
{
	double totalPrice = 0, tempPrice = initPrice;
	int last = 0;

	int queue[100000]; int front = -1, rear = -1;

	queue[++rear] = 0; //Root
	visited[0] = 1;

	GNode temp, cursor;

	while(front != rear)
	{
		cursor = temp = map->adjList[queue[++front]];

		if(leaf[temp->index])
			totalPrice += tempPrice * (leaf[temp->index]);

		while(temp->next)
		{
			temp = temp->next;
			if(visited[temp->index] == 0)
			{
				visited[temp->index] = 1;
				queue[++rear] = temp->index;
			}
		}

		if(cursor->index == last)
		{
			tempPrice = tempPrice * (1 + incrementRate / 100);
			last = queue[rear];
		}
	}

	return totalPrice;
}
