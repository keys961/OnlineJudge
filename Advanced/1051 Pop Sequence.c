#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int array[1000];
	int top;
}Stack;

int checkSequence(Stack stack, int* sequence, int M, int N);

int main()
{
	Stack stack;
	int* sequence = NULL;
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	sequence = (int*)malloc(sizeof(int) * N);

	for(int i = 0; i < K; i++)
	{
		stack.top = -1;
		if(checkSequence(stack, sequence, M, N))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

int checkSequence(Stack stack, int* sequence, int M, int N)
{
	int ptrSequence = 0;

	for(int i = 0; i < N; i++)
		scanf("%d", &sequence[i]);

	for(int i = 1; i <= N; i++)
	{
		while(stack.array[stack.top] == sequence[ptrSequence] && stack.top >= 0)
		{
			stack.top--;
			ptrSequence++;
		}
		stack.array[++stack.top] = i;
		if(stack.top == M) //Overflow
			return 0;
	}

	while(stack.top >= 0)
	{
		if(stack.array[stack.top] != sequence[ptrSequence])
			return 0;
		stack.top--;
		ptrSequence++;
	}
	return 1;
}