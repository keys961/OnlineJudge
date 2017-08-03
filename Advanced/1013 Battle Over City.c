#include <stdio.h>
#include <stdlib.h>

/*Use DFS to count connected graph
* Then count the number of roads
* Can also use DISJOINT SET
*/

int** Graph;
int visited[1000];

void initialize(int N);
int getNumber(int N);
void dfs(int i, int N);
void input(int** graph, int check[], int M, int K);

int main()
{
	int N, M, K; //number of cities/ number of remaining ways/ number of cities to be checked
	int** tempGraph;
	int check[1000] = {0,};
	scanf("%d %d %d", &N, &M, &K);

	Graph = (int**)malloc(sizeof(int*) * (N + 1));
	for(int i = 0; i <= N; i++)
        Graph[i] = (int*)malloc(sizeof(int) * (N + 1));
	tempGraph = (int**)malloc(sizeof(int*) * N);
	for(int i = 0; i <= N; i++)
        tempGraph[i] = (int*)malloc(sizeof(int) * (N + 1));

    initialize(N);
	input(tempGraph, check, M, K);

	for(int i = 0; i < K; i++)
	{
		for(int a = 0; a <= N; a++)
        {
            for(int b = 0; b <= N; b++)
                Graph[a][b] = tempGraph[a][b];
        }

		for(int j = 0; j <= N; j++)
			Graph[check[i]][j] = Graph[j][check[i]] = 0;

        initialize(N);

		printf("%d\n", getNumber(N) - 2);
	}

	return 0;
}

void initialize(int N)
{
	for(int i = 0; i <= N; i++)
		visited[i] = 0;
}

void input(int **graph, int check[], int M, int K)
{
	int a, b;
	for(int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}
	for(int i = 0; i < K; i++)
		scanf("%d", &check[i]);
}

int getNumber(int N)
{
	int num = 0;
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 0)
		{
			dfs(i, N);
			num++;
		}
	}
	return num;
}

void dfs(int i, int N)
{
	visited[i] = 1;
	for(int j = 1; j <= N; j++)
	{
		if(Graph[i][j] && visited[j] == 0)
			dfs(j, N);
	}
}
