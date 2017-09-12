#include <cstdio>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map< int, vector<int> > chain;

double bfs(double p, double r, int& same);

int main()
{
	int n;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);

	for (int i = 0; i < n; i++)
	{
		int k, val;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &val);
			chain[i].push_back(val);
		}
	}
	int same = 0;
	double price = bfs(p, r / 100, same);
	printf("%.4f %d\n", price, same);
	return 0;
}

double bfs(double p, double r, int& same)
{
	queue<int> q;
	q.push(0);
	int last = 0;
	int level = 0;
	double price = 0;
	same = 0;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		if (chain[temp].size() == 0)
		{
			price = p * pow(1 + r, level);
			same++;
		}
		for (int i = 0; i < chain[temp].size(); i++)
			q.push(chain[temp][i]);

		if (temp == last)
		{
			level++;
			if (!q.empty())
				last = q.back();
			if (price != 0)
				break;
		}
	}

	return price;
}