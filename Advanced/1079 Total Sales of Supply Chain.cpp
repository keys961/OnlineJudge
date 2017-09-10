#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

map< int, vector<int> > supplyChain;
vector<int> retailers;
double perPrice[100001];
int amount[100001];

double bfs(int n, double p, double r);

int main()
{
	int n;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	perPrice[0] = p;
	for (int i = 0; i < n; i++)
	{
		int k, receiver;
		scanf("%d", &k);
		if (k == 0)
		{
			retailers.push_back(i);
			scanf("%d", &amount[i]);
		}
		else
		{
			for (int j = 0; j < k; j++)
			{
				scanf("%d", &receiver);
				supplyChain[i].push_back(receiver);
			}
		}
	}

	printf("%.1f", bfs(n, p, r / 100));
	return 0;

}

double bfs(int n, double p, double r)
{
	double total = 0;

	queue<int> q;
	q.push(0);
	int level = 1;
	int last = 0;
	
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		perPrice[temp] = p * pow(1 + r, level - 1);
		for (int i = 0; i < supplyChain[temp].size(); i++)
			q.push(supplyChain[temp][i]);
		if (temp == last)
		{
			level++;
			if(!q.empty())
				last = q.back();
		}
	}

	for (int i = 0; i < retailers.size(); i++)
		total += amount[retailers[i]] * perPrice[retailers[i]];
	return total;
}