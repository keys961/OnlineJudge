#include <cstdio>
#include <cstring>

using namespace std;

int disjointSet[10001];
bool visited[10001];

int setFind(int person);
void setUnion(int a, int b);
int getCount(int& num)
{
	num = 0;
	int count = 0;
	for (int i = 1; i <= 10000; i++)
	{
		if (visited[i])
			num++;
		if (visited[i] && disjointSet[i] < 0)
			count++;
	}
	return count;
}

int main()
{
	int n, k, firstVal, val;
	int q;
	int num, c;
	memset(disjointSet, -1, sizeof(disjointSet));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		scanf("%d", &firstVal);
		visited[firstVal] = true;
		for (int j = 1; j < k; j++)
		{
			scanf("%d", &val);
			setUnion(firstVal, val);
			visited[val] = true;
		}
	}
	c = getCount(num);
	printf("%d %d\n", c, num);
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		if (setFind(v1) == setFind(v2))
			printf("Yes\n");
		else
			printf("No\n");
	}

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