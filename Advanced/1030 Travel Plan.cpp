#include <cstdio>
#include <list>

#define MAX_VALUE 0x7fffffff

using namespace std;

int cityDistMap[500][500];
int cityCostMap[500][500];

bool visited[500];
int dist[500];
int cost[500];
int path[500];

void init(int n);
list<int> solve(int src, int dst, int n);

int main()
{
	int n, m, s, d;
	scanf("%d %d %d %d", &n, &m, &s, &d);
	init(n);
	for (int i = 0; i < m; i++)
	{
		int c1, c2, dis, cos;
		scanf("%d %d %d %d", &c1, &c2, &dis, &cos);
		cityDistMap[c1][c2] = cityDistMap[c2][c1] = dis;
		cityCostMap[c1][c2] = cityCostMap[c2][c1] = cos;
	}
	list<int> res = solve(s, d, n);
	for (auto it = res.begin(); it != res.end(); it++)
		printf("%d ", *it);
	printf("%d %d\n", dist[d], cost[d]);
	return 0;
}

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		dist[i] = cost[i] = MAX_VALUE;
		path[i] = -1;
	}
}

list<int> solve(int src, int dst, int n)
{
	list<int> res;
	dist[src] = cost[src] = 0;
	for (; ;)
	{
		int minDist = MAX_VALUE;
		int minCity = -1;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				if (dist[i] < minDist)
				{
					minDist = dist[i];
					minCity = i;
				}
			}
		}

		if (minCity == -1)
			break;

		visited[minCity] = true;

		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && cityDistMap[minCity][i])
			{
				if (dist[i] > cityDistMap[minCity][i] + dist[minCity])
				{
					cost[i] = cityCostMap[minCity][i] + cost[minCity];
					path[i] = minCity;
					dist[i] = cityDistMap[minCity][i] + dist[minCity];
				}
				else if(dist[i] == cityDistMap[minCity][i] + dist[minCity])
				{
					if (cost[i] > cityCostMap[minCity][i] + cost[minCity])
					{
						cost[i] = cityCostMap[minCity][i] + cost[minCity];
						path[i] = minCity;
					}
				}
			}
		}
	}
	while (dst != -1)
	{
		res.push_front(dst);
		dst = path[dst];
	}
	return res;
}