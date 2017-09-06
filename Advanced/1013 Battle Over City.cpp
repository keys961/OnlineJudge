#include <cstdio>
#include <cstring>

using namespace std;

bool cityMap[1001][1001];
bool visited[1001];

int check(int city, int n);
void dfs(int city, int n);

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		cityMap[c1][c2] = 
			cityMap[c2][c1] = true;
	}
	
	for (int i = 0; i < k; i++)
	{
		int city;
		scanf("%d", &city);
		printf("%d\n", check(city, n));
	}

    return 0;
}

int check(int city, int n)
{
	memset(visited, false, sizeof(visited));
	visited[city] = true;
	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			count++;
			dfs(i, n);
		}
	}

	return count - 1;
}

void dfs(int city, int n)
{
	visited[city] = true;

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i] && cityMap[city][i])
			dfs(i, n);
	}
}