#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int disjointSet[19000];
int weight[19000];

struct Result
{
	int id;
	int gunNum;
	Result(int id, int gunNum)
	{
		this->id = id;
		this->gunNum = gunNum;
	}

	friend bool operator < (const Result& a, const Result& b)
	{
		return a.id < b.id;
	}
};

int hashcode(char* name)
{
	return (name[0] - 'A') * 26 * 26 +
		(name[1] - 'A') * 26 + name[2] - 'A';
}

char* getName(int hashCode)
{
	char* name = new char[4];
	for (int i = 2; i >= 0; i--)
	{
		name[i] = 'A' + hashCode % 26;
		hashCode /= 26;
	}
	name[3] = 0;
	return name;
}

int find(int id)
{
	while (disjointSet[id] >= 0)
		id = disjointSet[id];
	return id;
}

void setUnion(int idA, int idB)
{
	int headA = find(idA);
	int headB = find(idB);
	if (headA == headB)
		return;
	if (disjointSet[headA] < disjointSet[headB])
	{
		disjointSet[headA] += disjointSet[headB];
		disjointSet[headB] = headA;
	}
	else
	{
		disjointSet[headB] += disjointSet[headA];
		disjointSet[headA] = headB;
	}
}

void findHead(int k);

int main()
{
	int n, k, time;
	char name1[4], name2[4];
	scanf("%d %d", &n, &k);
	memset(disjointSet, -1, sizeof(disjointSet));
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s %d", name1, name2, &time);
		int id1 = hashcode(name1);
		int id2 = hashcode(name2);
		weight[id1] += time;
		weight[id2] += time;
		setUnion(id1, id2);
	}
	findHead(k);
	return 0;
}

void findHead(int k)
{
	set<Result> res;
	for (int i = 0; i < 19000; i++)
	{
		int id, headId;
		int totalMin = 0;
		if (disjointSet[i] < -2)
		{
			headId = i;
			for (int j = 0; j < 19000; j++)
			{
				if (find(j) == i)
				{
					totalMin += weight[j];
					if (weight[headId] < weight[j])
						headId = j;
				}
			}
			if (totalMin > 2 * k)
				res.insert(Result(headId, -disjointSet[i]));
		}
	}
	if (res.size() == 0)
		printf("0\n");
	else
	{
		printf("%d\n", res.size());
		for (auto it = res.begin(); it != res.end(); it++)
			printf("%s %d\n", getName(it->id), it->gunNum);
	}
}