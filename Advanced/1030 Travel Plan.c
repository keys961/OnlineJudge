#include <stdio.h>
#include <stdlib.h>

#define INFINITY 1<<30

typedef struct node
{
	int dist;
	int cost;
}Node;

Node map[500][500];
int dist[500];
int cost[500];
int path[500];
int visited[500];

void findShortestPath(int str, int dst, int N);
void initialize(int N);
void input(int M);
int findShortestDist(int N);
void printPath(int dst);

int main()
{
	int N, M, str, dst;
	scanf("%d %d %d %d", &N, &M, &str, &dst);

	initialize(N);
	input(M);

	findShortestPath(str, dst, N);
	printPath(dst);

	printf("%d %d\n", dist[dst], cost[dst]);

	return 0;
}

void initialize(int N)
{
	for(int i = 0; i < N; i++)
	{
		dist[i] = cost[i] = INFINITY;
		path[i] = -1;
		visited[i] = 0;
		for(int j = 0; j < N; j++)
			map[i][j].dist = map[i][j].cost = 0;
	}
}

void input(int M)
{
	int city1, city2, dist, cost;
	for(int i = 0; i < M; i++)
	{
		scanf("%d %d %d %d", &city1, &city2, &dist, &cost);
		map[city1][city2].dist = map[city2][city1].dist = dist;
		map[city1][city2].cost = map[city2][city1].cost = cost;
	}
}

void findShortestPath(int str, int dst, int N)
{
	int temp;
	//visited[str] = 1;
	path[str] = -1;
	cost[str] = 0;
	dist[str] = 0;

	while(1)
	{
		temp = findShortestDist(N);
		if(temp == -1)
			break;

		visited[temp] = 1;
		if(temp == dst)
			break;

		for(int i = 0; i < N; i++)
		{
			if(visited[i] == 0 && map[temp][i].dist > 0)
			{
				if(dist[temp] + map[temp][i].dist < dist[i])
				{
					dist[i] = dist[temp] + map[temp][i].dist;
					path[i] = temp;
					cost[i] = cost[temp] + map[temp][i].cost;
				}
				else if(dist[temp] + map[temp][i].dist == dist[i])
					if(cost[i] > cost[temp] + map[temp][i].cost)
					{
						path[i] = temp;
						cost[i] = cost[temp] + map[temp][i].cost;
					}
			}
		}
	}
}

int findShortestDist(int N)
{
	int minDist = INFINITY;
	int minIndex = -1;

	for(int i = 0; i < N; i++)
	{
		if(!visited[i])
			if(dist[i] < minDist)
			{
				minDist = dist[i];
				minIndex = i;
			}
	}

	return minIndex;
}

void printPath(int dst)
{
	int stack[500];
	int top = -1;

	while(dst != -1)
	{
		stack[++top] = dst;
		dst = path[dst];
	}

	for(int i = top; i >= 0; i--)
		printf("%d ", stack[i]);
}
