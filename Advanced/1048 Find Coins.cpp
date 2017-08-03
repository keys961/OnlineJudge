#include <stdio.h>
#include <stdlib.h>

using namespace std;

int coins[100000] = {0, };

int compare(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}

int solve(int n, int m);

int main(int argc, char const *argv[])
{
	int N, M;//Number of coins, target
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", &coins[i]);
	qsort(coins, N, sizeof(int), compare);
	if(!solve(N, M))
		printf("No Solution\n");
	
	return 0;
}

int solve(int n, int m)
{
	int begin = 0, end = n - 1;
	while(coins[begin] + coins[end] > m && begin < end)
		begin++;
	while(coins[begin] + coins[end] < m && begin < end)
		end--;
	if(coins[begin] + coins[end] == m)
	{
		printf("%d %d\n", coins[end], coins[begin]);
		return 1;
	}
	return 0;
}