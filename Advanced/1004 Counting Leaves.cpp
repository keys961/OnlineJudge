#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <queue>

using namespace std;

map< int, vector<int> > familyTree;

vector<int> solve(int root);

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int parent, k, child;
		scanf("%d %d", &parent, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			familyTree[parent].push_back(child);
		}
	}

	vector<int> res = solve(01);
	for (int i = 0; i < res.size() - 1; i++)
		printf("%d ", res[i]);
	printf("%d\n", res[res.size() - 1]);

    return 0;
}

vector<int> solve(int root)
{
	vector<int> result;
	queue<int> q;
	int last = root;
	int levelCount = 0;
	q.push(root);

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		if (familyTree.find(temp) == familyTree.end())
			levelCount++;
		else
		{
			for (int i = 0; i < familyTree[temp].size(); i++)
				q.push(familyTree[temp][i]);
		}
		if (temp == last)
		{
			result.push_back(levelCount);
			if(!q.empty())
				last = q.back();
			levelCount = 0;
		}
	}
	
	return result;
}