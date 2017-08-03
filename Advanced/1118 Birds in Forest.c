#include <stdio.h>
#include <stdlib.h>

int findRoot(int* disjointSet, int index);
void setUnion(int* disjointSet, int A, int B);
void initialization(int* disjointSet);
void input(int* disjointSet, int n);
void count(int* disjointSet, int* pictures, int* birds);

int visited[10001] = {0, };

int main()
{
	int n, q, a, b;
	int pictures = 0, birds = 0;
	int disjointSet[10001];
	initialization(disjointSet);

	scanf("%d", &n);
	input(disjointSet, n);
	count(disjointSet, &pictures, &birds);
	printf("%d %d\n", pictures, birds);

	scanf("%d", &q);
	for(int i = 0 ; i < q; i++)
	{
		scanf("%d %d", &a, &b);
		if(findRoot(disjointSet, a) == findRoot(disjointSet, b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

void input(int* disjointSet, int n)
{
	int k, temp, index;
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &k, &temp);
		visited[temp] = 1;
		for(int j = 0; j < k - 1; j++)
		{
			scanf("%d", &index);
			visited[index] = 1;
			setUnion(disjointSet, temp, index);
		}
	}
}

void initialization(int* disjointSet)
{
	for(int i = 0; i < 10001; i++)
		disjointSet[i] = -1;
}

int findRoot(int* disjointSet, int index)
{
	int i = index;
	while(disjointSet[i] >= 0)
		i = disjointSet[i];
	return i;
}

void setUnion(int* disjointSet, int A, int B)
{
	int rootA = findRoot(disjointSet, A);
	int rootB = findRoot(disjointSet, B);
	if(rootA == rootB)
		return;
	if(disjointSet[rootA] > disjointSet[rootB])
	{
		disjointSet[rootB] += disjointSet[rootA];
		disjointSet[rootA] = rootB;
	}
	else
	{
		disjointSet[rootA] += disjointSet[rootB];
		disjointSet[rootB] = rootA;
	}
}

void count(int* disjointSet, int* pictures, int* birds)
{
	for(int i = 1; i < 10001; i++)
		if(visited[i] == 1)
			(*birds)++;
	for(int i = 1; i <= (*birds); i++)
        if(disjointSet[i] < 0)
            (*pictures)++;
}
