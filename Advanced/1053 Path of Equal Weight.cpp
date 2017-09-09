#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map< int, vector<int> > tree;
int weight[100];

bool compare(int a, int b)
{
	return weight[a] > weight[b];
}

void dfs(int n, int s, int id, vector<int> path);

int main()
{
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &weight[i]);

	for (int i = 0; i < m; i++)
	{
		int root, k, child;
		scanf("%d %d", &root, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			tree[root].push_back(child);
		}
		sort(tree[root].begin(), tree[root].end(), compare);
	}
	dfs(n, s - weight[0], 0, vector<int>());
	return 0;
}

void dfs(int n, int s, int id, vector<int> path)
{
	if (s < 0)
		return;
	path.push_back(weight[id]);
	if (s == 0 && tree[id].size() == 0)
	{
		for (int i = 0; i < path.size() - 1; i++)
			printf("%d ", path[i]);
		printf("%d\n", path[path.size() - 1]);
		return;
	}

	for (int i = 0; i < tree[id].size(); i++)
		dfs(n, s - weight[tree[id][i]], tree[id][i], path);
}