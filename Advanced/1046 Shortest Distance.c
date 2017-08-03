#include <stdio.h>
#include <stdlib.h>

int query(int* distance, int n, int a, int b, int sum);

int main()
{
	int n, sum = 0, temp;
	int q, a, b;
	int* distance;
	scanf("%d", &n);
	distance = (int*)malloc(sizeof(int) * (n + 3));
	distance[1] = 0;
	for(int i = 1; i <= n; i++)
	{
		//scanf("%d", &distance[i]); //Overtime
		scanf("%d", &temp);
		distance[i + 1] = distance[i] + temp; //Accumulation!
		sum += temp; //Just do the substraction, O(1)
	}

	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", query(distance, n, a, b, sum));
	}
	return 0;
}

int query(int* distance, int n, int a, int b, int sum)
{
	int A = (a > b) ? b : a;
	int B = (a > b) ? a : b;
	int dist = distance[B] - distance[A];
	// for(int i = A; i < B; i++) No need to traversal
	// 	dist += distance[i];
	return (dist > (sum - dist)) ? (sum - dist) : dist;
}
