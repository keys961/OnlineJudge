#include <cstdio>
#include <cstring>

using namespace std;

bool graph[201][201];
bool visited[201];

int query[1000];

bool check(int n, int k);

int main()
{
	int n, m, k;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) 
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = graph[v2][v1] = true;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int nv;
		scanf("%d", &nv);
		for (int j = 0; j < nv; j++)
			scanf("%d", &query[j]);
		if (check(n, nv))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

bool check(int n, int k)
{
	memset(visited, false, sizeof(visited));
	if (n + 1 != k || query[k - 1] != query[0])
		return false;
	int last = -1;
	for (int i = 0; i <= n; i++)
	{
		if (i == n)
		{
			if (graph[last][query[i]])
				return true;
			else
				return false;
		}
		else if (!visited[query[i]] && (last == -1 || graph[last][query[i]]))
		{
			last = query[i];
			visited[query[i]] = true;			
		}
		else
			return false;
	}
	return true;
}