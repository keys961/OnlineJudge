#include <stdio.h>
#include <stdlib.h>

int graph[201][201] = {0,};
int visited[201] = {0,};

void input(int m);
void initVisited(int n);
int query(int n);

int main()
{
	int n, m, q;
	scanf("%d %d", &n, &m);
	input(m);
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		initVisited(n);
		if(query(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

void initVisited(int n)
{
	for(int i = 1; i <= n; i++)
		visited[i] = 0;
}

void input(int m)
{
	int vertex1, vertex2;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &vertex1, &vertex2);
		graph[vertex1][vertex2] = 1;
		graph[vertex2][vertex1] = 1;
	}
}

int query(int n)
{
	int flag = 1;
	int queryNum;
	int start, current, next;
	scanf("%d", &queryNum);
	if(queryNum != n + 1)
	{
		for(int i = 0; i < queryNum; i++)
			scanf("%d", &current);
		return 0;
	}
	else
	{
		scanf("%d", &start);
		visited[start] = 1;
		current = start;
		for(int i = 1; i < queryNum; i++)
		{
			scanf("%d", &next);
			if((i < queryNum - 1 && next == start) ||
				graph[current][next] == 0 || (visited[next] && next != start)
				|| (i == queryNum - 1 && next != start))
				flag = 0;
			visited[next] = 1;
			current = next;
		}
	}
	return flag;
}
