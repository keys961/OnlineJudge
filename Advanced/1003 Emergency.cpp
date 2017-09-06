#include <cstdio>
#include <cstdlib>

using namespace std;

int rescueTeams[500];
int cityMap[500][500];

bool visited[500];
int dist[500];
int routines[500];
int teamsGathered[500];

void solve(int src, int dst, int n);

int main()
{
	int n, m, c1, c2;
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		dist[i] = 0x7fffffff;
		teamsGathered[i] = 0;
		scanf("%d", &rescueTeams[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		cityMap[a][b] = cityMap[b][a] = c;
	}
	solve(c1, c2, n);
	printf("%d %d\n", routines[c2], teamsGathered[c2]);
    return 0;
}

void solve(int src, int dst, int n)
{
	dist[src] = 0;
	teamsGathered[src] = rescueTeams[src];
	routines[src] = 1;
	while (true)
	{
		int minDist = 0x7fffffff;
		int city = -1;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				if (dist[i] < minDist)
				{
					minDist = dist[i];
					city = i;
				}
			}
		}

		if (city == -1)
			break;

		visited[city] = true;
		if (city == dst)
			break;

		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && cityMap[city][i])
			{
				
				if (dist[i] > dist[city] + cityMap[city][i])
				{
					routines[i] = routines[city];
					dist[i] = dist[city] + cityMap[city][i];
					teamsGathered[i] = teamsGathered[city] + rescueTeams[i];
				}
				else if (dist[i] == dist[city] + cityMap[city][i])
				{
					routines[i] += routines[city];
					if (teamsGathered[i] < teamsGathered[city] + rescueTeams[i])
						teamsGathered[i] = teamsGathered[city] + rescueTeams[i];
				}
			}
		}
	}
}
