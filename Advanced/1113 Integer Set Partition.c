#include <stdio.h>

int cmp(const void* a, const void* b);

int main()
{
	int N;
	int N1, N2;
	int sum1 = 0, sum2 = 0;
	int* nums = NULL;

	scanf("%d", &N);

	nums = (int*)malloc(sizeof(int) * N);

	for(int i = 0; i < N; i++)
		scanf("%d", &nums[i]);

	qsort(nums, N, sizeof(int), cmp);

	N1 = N / 2;
	N2 = N - N1;

	for(int i = 0; i < N1; i++)
		sum1 += nums[i];
	for(int i = N1; i < N; i++)
		sum2 += nums[i];

	printf("%d %d\n", N2 - N1, sum2 - sum1);
	return 0;
}

int cmp(const void* a, const void* b)
{
	return (*(int*)a) - (*(int*)b);
}