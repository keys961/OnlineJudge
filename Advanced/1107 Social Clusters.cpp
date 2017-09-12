#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int disjointSet[1001];

map< int, vector<int> > personHobby; //P - H
map< int, vector<int> > hobbyPerson; // H - P

int setFind(int person);
void setUnion(int a, int b);
bool compare(int a, int b)
{
	return a > b;
}

vector<int> res;

int main()
{
	int n;
	scanf("%d", &n);
	memset(disjointSet, -1, sizeof(disjointSet));
	for (int i = 1; i <= n; i++)
	{
		int k, val;
		scanf("%d:", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &val);
			personHobby[i].push_back(val);
			hobbyPerson[val].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < personHobby[i].size(); j++)
		{
			for (int k = 0; k < hobbyPerson[personHobby[i][j]].size(); k++)
				setUnion(i, hobbyPerson[personHobby[i][j]][k]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (disjointSet[i] < 0)
			res.push_back(-disjointSet[i]);
	}
	sort(res.begin(), res.end(), compare);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size() - 1; i++)
		printf("%d ", res[i]);
	printf("%d\n", res.back());
	return 0;
}

int setFind(int person)
{
	while (disjointSet[person] >= 0)
		person = disjointSet[person];
	return person;
}

void setUnion(int a, int b)
{
	int p1 = setFind(a);
	int p2 = setFind(b);

	if (p1 == p2)
		return;

	if (disjointSet[p1] < disjointSet[p2])
	{
		disjointSet[p1] += disjointSet[p2];
		disjointSet[p2] = p1;
	}
	else
	{
		disjointSet[p2] += disjointSet[p1];
		disjointSet[p1] = p2;
	}
}