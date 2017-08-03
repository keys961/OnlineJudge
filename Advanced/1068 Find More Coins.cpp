#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int coins[10000];
vector<int> res;

int solve(int n, int m);
int max(int a, int b);
int compare(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", &coins[i]);
	qsort(coins, N, sizeof(int), compare);
	if(solve(N, M))
	{
		for(int i = 0; i < res.size() - 1; i++)
			printf("%d ", res[i]);
		printf("%d\n", res[res.size() - 1]);
	}
	else
		printf("No Solution\n");
	return 0;
}

int solve(int n, int m)
{
	int** dp;
	for(int i = 0; i < n; i++)
		dp = (int**)malloc(sizeof(int*) * n);
	for(int j = 0; j < n; j++)
		dp[j] = (int*)malloc(sizeof(int) * (m + 1));

	for(int i = 0; i <= m; i++)
	{
		if(coins[0] > i)
			dp[0][i] = 0;
		else
			dp[0][i] = coins[0];
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < coins[i]; j++)
			dp[i][j] = 0;
		for(int j = coins[i]; j <= m; j++)
			dp[i][j] = max(dp[i - 1][j - coins[i]] + coins[i], dp[i - 1][j]);
	}
	if(dp[n - 1][m] != m)
		return 0;
	else
	{
		int i = n - 1, j = m;
		while(j > 0 && i >= 0)
		{
			if(i > 0)
			{
				if(dp[i - 1][j - coins[i]] + coins[i] 
					>= dp[i - 1][j])
				{
					j -= coins[i];
					res.push_back(coins[i]);
				}
			}
			else
				res.push_back(coins[i]);
			i--;
		}
		return 1;
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}