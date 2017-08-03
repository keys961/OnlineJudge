#include <stdlib.h>

int GetMax(int A[], int n, int *left, int *right) //Use the algorithm of which the T(N) = O(N)
{
	int thisSum, maxSum;
	int i;
	int flag = 0; //Jugde thisSum is negative or not
	int isNegative = 1; //Jugde the elements in the array are all negative or not
	int temp;
	thisSum = maxSum = 0;
	*left = *right = 0;
	for(i = 0; i < n; i++)
	{
		thisSum += A[i];
		if(A[i] == 0 && isNegative)
		{
			*left = *right = i;
			isNegative = 0;
		}
		if(thisSum > maxSum)
		{
			maxSum = thisSum;
			isNegative = 0;
			if(flag)
			{
				*left = temp + 1;
				flag = 0;
			}
			*right = i;
		}
		else if(thisSum < 0)
		{
			flag = 1;
			temp = i;
			thisSum = 0;
		}
	}
	if(isNegative)
		*right = n - 1;
	return maxSum;
}

int main()
{
	int n, i, left, right;
	int max;
	int *nums = NULL;
	scanf("%d", &n);
	nums = (int*)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%d", &nums[i]);
	max = GetMax(nums, n, &left, &right);
	printf("%d %d %d\n", max, nums[left], nums[right]);
	return 0;
}
