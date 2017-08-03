#include <stdio.h>
#include <stdlib.h>

void input(int N, int* initSequence, int* cmpSequence, int* tempSequence);
int insertionSort(int* initSequence, int* cmpSequence, int N);
void heapSort(int* tempSequence, int N);
void buildHeap(int* tempSequence, int index, int N);
int compare(int* initSequence, int* cmpSequence, int N);

int main()
{
	int cmpSequence[100];
	int initSequence[100];
	int tempSequence[100]; //For 2ND CMP
	int N;
	scanf("%d", &N);
	input(N, initSequence, cmpSequence, tempSequence);
	if(insertionSort(initSequence, cmpSequence, N))
	{
		printf("Insertion Sort\n");
		for(int i = 0; i < N - 1; i++)
			printf("%d ", initSequence[i]);
		printf("%d\n", initSequence[N - 1]);
	}
	else
	{
		printf("Heap Sort\n");
		heapSort(tempSequence, N);
		for(int i = 0; i < N - 1; i++)
			printf("%d ", tempSequence[i]);
		printf("%d\n", tempSequence[N - 1]);
	}


	return 0;
}

void input(int N, int* initSequence, int* cmpSequence, int* tempSequence)
{
	for(int i = 0; i < N; i++)
		scanf("%d", &initSequence[i]);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &cmpSequence[i]);
		tempSequence[i] = cmpSequence[i];
	}
}

int compare(int* initSequence, int* cmpSequence, int N)
{
	for(int i = 0; i < N; i++)
		if(initSequence[i] != cmpSequence[i])
			return 0;
	return 1;
}

int insertionSort(int* initSequence, int* cmpSequence, int N)
{
	int A, i, j;
	for(i = 1; i < N; i++)
	{
		A = initSequence[i];
		for(j = i; j > 0; j--)
		{
			if(initSequence[j - 1] > A)
				initSequence[j] = initSequence[j - 1];
			else
				break;
		}
		initSequence[j] = A;
		if(compare(initSequence, cmpSequence, N))//No
			break;
	}
	if(i == N)
		return 0;
	else //Next iteration
	{
		A = initSequence[++i];
		for(j = i; j > 0; j--)
		{
			if(initSequence[j - 1] > A)
				initSequence[j] = initSequence[j - 1]; //Shift not swap
			else
				break;
		}
		initSequence[j] = A;
		return 1;
	}
}

void heapSort(int* tempSequence, int N)
{
	int i, temp;
	int A = tempSequence[0];

	for(i = 0; i < N; i++)
		if(tempSequence[i] > A)
			break;

	temp = A;
	tempSequence[0] = tempSequence[i - 1];
	tempSequence[i - 1] = temp;

	buildHeap(tempSequence, 0, i - 2);

}

void buildHeap(int* sequence, int index, int N)
{
	int temp = sequence[index];
	int i;
	int child;
	for(i = index; 2 * i + 1 <= N; i = child)
	{
		child = 2 * i + 1;
		if(child < N && sequence[child + 1] > sequence[child])
			child++;
		if(sequence[child] > temp)
			sequence[i] = sequence[child];
		else
			break;
	}
	sequence[i] = temp;
}
