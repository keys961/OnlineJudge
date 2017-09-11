#include <cstdio>
#include <map>
#include <queue>
#include <vector>

using namespace std;

map< int, vector<int> > familyTree;

void solve(int& size, int& level);

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int root, k, child;
		scanf("%d %d", &root, &k);

		for (int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			familyTree[root].push_back(child);
		}
	}
	int size, level;
	solve(size, level);
	printf("%d %d\n", size, level);

	return 0;
}

void solve(int& size, int& level)
{
	size = 0, level = 1;
	queue<int> q;
	q.push(1);
	int l = 1;
	int count = 0;
	int last = 1;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		count++;

		for (int i = 0; i < familyTree[temp].size(); i++)
			q.push(familyTree[temp][i]);

		if (temp == last)
		{
			if (count > size)
			{
				size = count;
				level = l;
			}
			l++;
			count = 0;
			if (!q.empty())
				last = q.back();
		}
	}
}