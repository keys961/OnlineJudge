#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int lCityMap[500][500];
int tCityMap[500][500];

int dist[500];
int times[500];
int intersection[500];
int path[500];
bool visited[500];

vector<int> pathDist;
vector<int> pathTime;

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		dist[i] = times[i] = intersection[i] = 0x7fffffff;
		path[i] = -1;
		visited[i] = false;
	}
}
int getMinDistPath(int src, int dst, int n);
int getMinTimePath(int src, int dst, int n);

int main()
{
	int n, m;
	int v1, v2, ow, l, t;
	int src, dst;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d %d %d", &v1, &v2, &ow, &l, &t);
		lCityMap[v1][v2] = l;
		tCityMap[v1][v2] = t;
		if (!ow)
		{
			lCityMap[v2][v1] = l;
			tCityMap[v2][v1] = t;
		}
	}
	scanf("%d %d", &src, &dst);
	int resDist = getMinDistPath(src, dst, n);
	int resTime = getMinTimePath(src, dst, n);
	if (pathDist == pathTime)
	{
		printf("Distance = %d; Time = %d: %d", resDist, resTime, src);
		for (int i = 1; i < pathDist.size(); i++)
			printf(" -> %d", pathDist[i]);
		printf("\n");
	}
	else
	{
		printf("Distance = %d: %d", resDist, src);
		for (int i = 1; i < pathDist.size(); i++)
			printf(" -> %d", pathDist[i]);
		printf("\n");

		printf("Time = %d: %d", resTime, src);
		for (int i = 1; i < pathTime.size(); i++)
			printf(" -> %d", pathTime[i]);
		printf("\n");
	}
	return 0;
}

int getMinDistPath(int src, int dst, int n)
{
	init(n);
	dist[src] = 0;
	times[src] = 0;

	while (true)
	{
		int minV = -1;
		int minDist = 0x7fffffff;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && dist[i] < minDist)
			{
				minDist = dist[i];
				minV = i;
			}
		}

		if (minV == -1)
			break;
		visited[minV] = true;

		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && lCityMap[minV][i])
			{
				if (dist[i] > dist[minV] + lCityMap[minV][i])
				{
					path[i] = minV;
					dist[i] = dist[minV] + lCityMap[minV][i];
					times[i] = times[minV] + tCityMap[minV][i];
				}
				else if (dist[i] == dist[minV] + lCityMap[minV][i])
				{
					if (times[i] > times[minV] + tCityMap[minV][i])
					{
						path[i] = minV;
						times[i] = times[minV] + tCityMap[minV][i];
					}
				}
			}
		}
	}
	int d = dist[dst];
	while (dst != -1)
	{
		pathDist.push_back(dst);
		dst = path[dst];
	}
	
	reverse(pathDist.begin(), pathDist.end());
	return d;
}

int getMinTimePath(int src, int dst, int n)
{
	init(n);
	times[src] = 0;
	intersection[src] = 0;

	while (true)
	{
		int minV = -1;
		int minTime = 0x7fffffff;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && times[i] < minTime)
			{
				minTime = times[i];
				minV = i;
			}
		}

		if (minV == -1)
			break;
		visited[minV] = true;

		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && tCityMap[minV][i])
			{
				if (times[i] > times[minV] + tCityMap[minV][i])
				{
					times[i] = times[minV] + tCityMap[minV][i];
					path[i] = minV;
					intersection[i] = intersection[minV] + 1;
				}
				else if (times[i] == times[minV] + tCityMap[minV][i])
				{
					if (intersection[i] > intersection[minV] + 1)
					{
						path[i] = minV;
						intersection[i] = intersection[minV] + 1;
					}
				}
			}
		}
	}
	int t = times[dst];
	while (dst != -1)
	{
		pathTime.push_back(dst);
		dst = path[dst];
	}
	
	reverse(pathTime.begin(), pathTime.end());
	return t;
}