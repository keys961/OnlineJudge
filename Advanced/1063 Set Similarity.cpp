#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< set<long long> > sets;

double getSimilarity(int id1, int id2);

int main()
{
	int n, m;
	long long val;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		set<long long> newSet;
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			scanf("%lld", &val);
			if (newSet.find(val) == newSet.end())
				newSet.insert(val);
		}
		sets.push_back(newSet);
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int id1, id2;
		scanf("%d %d", &id1, &id2);
		printf("%.1f%%\n", getSimilarity(id1, id2));
	}
	return 0;
}

double getSimilarity(int id1, int id2)
{
	int countSame = 0;
	auto it1 = sets[id1 - 1].begin();
	auto it2 = sets[id2 - 1].begin();

	while (it1 != sets[id1 - 1].end() && it2 != sets[id2 - 1].end())
	{
		if (*it1 < *it2)
			it1++;
		else if (*it1 > *it2)
			it2++;
		else
		{
			countSame++;
			it2++;
			it1++;
		}
	}

	return countSame * 100.0 /
		(sets[id1 - 1].size() + sets[id2 - 1].size() - countSame);
}