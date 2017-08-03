#include <stdio.h>
#include <stdlib.h>

#define INFINITY 1<<30

int weightGraph[500][500];
int teamNum[500];

int dist[500];
int countRoutine[500]; //Number of routines
int countRescue[500]; //Number of rescue teams
int visited[500];

void initialization(int N);
void input(int N, int M);
void findPath(int N, int C1);

int main()
{
	int N, M, C1, C2;
	scanf("%d %d %d %d", &N, &M, &C1, &C2);
	initialization(N);
	input(N, M);
	findPath(N, C1);
	printf("%d %d\n", countRoutine[C2], countRescue[C2]);
	return 0;
}

void initialization(int N)
{
	for(int i = 0 ; i < N; i++)
	{
		teamNum[i] = 0;
		visited[i] = 0;
		countRescue[i] = 0;
		countRoutine[i] = 0;
		dist[i] = INFINITY;
		for(int j = 0; j < N; j++)
			weightGraph[i][j] = 0;
	}
}

void input(int N, int M)
{
	int c1, c2, weight;
	for(int i = 0; i < N; i++)
		scanf("%d", &teamNum[i]);
	for(int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &c1, &c2, &weight);
		weightGraph[c1][c2] = weightGraph[c2][c1] = weight;
	}
}

void findPath(int N, int C1)
{
	int minVertex;
	int minDist;

	dist[C1] = 0;
	countRoutine[C1] = 1;
	countRescue[C1] = teamNum[C1];

	while(1)
	{
		minVertex = -1;
		minDist = INFINITY;
		for(int i = 0; i < N; i++)
		{
			if(dist[i] < minDist && visited[i] == 0)
			{
				minDist = dist[i];
				minVertex = i;
			}
		}
		if(minVertex == -1)
			break;

		visited[minVertex] = 1;

		for(int i = 0; i < N; i++)
		{
			if(weightGraph[minVertex][i] > 0 && visited[i] == 0)
			{
				if(weightGraph[minVertex][i] + dist[minVertex] < dist[i])
				{
					dist[i] = weightGraph[minVertex][i] + dist[minVertex];
					countRoutine[i] = countRoutine[minVertex];
					countRescue[i] = countRescue[minVertex] + teamNum[i];
				}
				else if(weightGraph[minVertex][i] + dist[minVertex] == dist[i])
				{
					countRoutine[i] += countRoutine[minVertex];
					if(countRescue[minVertex] + teamNum[i] > countRescue[i])
						countRescue[i] = countRescue[minVertex] + teamNum[i];
				}
			}
		}
	}
}