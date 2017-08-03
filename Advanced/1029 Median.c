#include <stdio.h>
#include <stdlib.h>

void input(long* sequence, int N);
void merge(long* sequenceA, int A, long* sequenceB, int B, long* result, int* res);

int main()
{
	long* sequenceA = NULL, *sequenceB = NULL, *result;
	int A, B, res;
	scanf("%d", &A);
	sequenceA = (long*)malloc(sizeof(long) * A);
	input(sequenceA, A);
	scanf("%d", &B);
	sequenceB = (long*)malloc(sizeof(long) * B);
	input(sequenceB, B);
	result = (long*)malloc(sizeof(long) * (A + B));

	merge(sequenceA, A, sequenceB, B, result, &res);

	printf("%ld\n", result[(res - 1) / 2]);
	return 0;
}

void input(long* sequence, int N)
{
	for(int j = 0; j < N; j++)
		scanf("%ld", &sequence[j]);
}

void merge(long* sequenceA, int A, long* sequenceB, int B, long* result, int* res)
{
	int ptrA = 0, ptrB = 0, ptrR = 0;
	while(ptrA < A && ptrB < B)
	{
		if(sequenceA[ptrA] < sequenceB[ptrB])
            result[ptrR++] = sequenceA[ptrA++];

		else if(sequenceA[ptrA] == sequenceB[ptrB])
		{
            result[ptrR++] = sequenceA[ptrA++];
            ptrB++;
		}
		else
            result[ptrR++] = sequenceB[ptrB++];
	}

	while(ptrA < A)
		result[ptrR++] = sequenceA[ptrA++];
	while(ptrB < B)
		result[ptrR++] = sequenceB[ptrB++];

    *res = ptrR;
}
