#include <stdio.h>
#include <stdlib.h>

int CmpArray[100]; //Compared Array, Global
int flag = 0; //1: Insert, 2: Merge

void PrintArray(int A[], int N);
int Compare(int A[], int N);
void CopyArray(int DstArray[], int SrcArray[], int N);
void InsertSort(int A[], int N);
//Merge 1-2-4-...2^n element-sublist, without recursion
//Guess the length of merged sublist
void MergeSort(int A[], int N);
void MergePass(int A[], int temp[], int N, int length);
void Merge(int A[], int temp[], int leftStart, int rightStart, int rightEnd);

int main()
{
	int N, i;
	int InitArray[100];
	int A[100];
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &InitArray[i]);
	for(i = 0; i < N; i++)
		scanf("%d", &CmpArray[i]);
	CopyArray(A, InitArray, N);
	MergeSort(A, N);
	if(flag != 1)
	{
		CopyArray(A, InitArray, N); //If not using insertion sort, it must be merge sort.
		InsertSort(A, N);
	}
	return 0;
}

void PrintArray(int A[], int N)
{
	int i;
	for(i = 0; i < N - 1; i++)
		printf("%d ", A[i]);
	printf("%d\n", A[i]);
}

int Compare(int A[], int N)
{
	int flag = 1;
	int i;
	for(i = 0; i < N; i++)
	{
		if(CmpArray[i] != A[i])
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

void CopyArray(int DstArray[], int SrcArray[], int N)
{
	int i;
	for(i = 0; i < N; i++)
		DstArray[i] = SrcArray[i];
}

void InsertSort(int A[], int N)
{
	int temp, i, j;
	for(i = 1; i < N; i++)
	{
		temp = A[i];
		for(j = i; j > 0; j--)
		{
			if(A[j - 1] > temp)
				A[j] = A[j - 1];
			else
				break; //if break, the pos before it, sublist is sorted
		}
		A[j] = temp;
		if(Compare(A, N))
		{
			flag = 1;
			printf("Insertion Sort\n");
			break;
		}
	}
	if(i == N)
		return;
	//next iteration
	i++;
	temp = A[i];
	for(j = i; j > 0; j--)
	{
		if(A[j - 1] > temp)
			A[j] = A[j - 1];
		else
			break; //if break, the pos before it, sublist is sorted
	}
	A[j] = temp;
	PrintArray(A, N);
}

void MergeSort(int A[], int N)
{
	int length;
	int* temp = (int*)malloc(sizeof(int) * N);
	length = 1;
	while(length < N)
	{
		MergePass(A, temp, N, length);
		length *= 2;
		if(Compare(A, N))
		{
			printf("Merge Sort\n");
			if(length < N)
                MergePass(A, temp, N, length);
			PrintArray(A, N);
			flag = 1;
			break;
		}
	}
}

void MergePass(int A[], int temp[], int N, int length)
{
	int i, j;
	for(i = 0; i <= N - 2 * length; i += 2 * length)
		Merge(A, temp, i, i + length, i + 2 * length - 1);
	if(i + length < N)
		Merge(A, temp, i, i + length, N - 1);
	else
		for(j = i; j < N; j++)
			temp[j] = A[j];
}

void Merge(int A[], int temp[], int leftStart, int rightStart, int rightEnd)
{
	int leftEnd, numElement, tempPtr;
	int i;
	leftEnd = rightStart - 1;
	numElement = rightEnd - leftStart + 1;
	tempPtr = leftStart;

	while(leftStart <= leftEnd && rightStart <= rightEnd)
	{
		if(A[leftStart] < A[rightStart])
			temp[tempPtr++] = A[leftStart++];
		else
			temp[tempPtr++] = A[rightStart++];
	}

	while(leftStart <= leftEnd)
		temp[tempPtr++] = A[leftStart++];
	while(rightStart <= rightEnd)
		temp[tempPtr++] = A[rightStart++];

	for(i = 0; i < numElement; i++, rightEnd--)
        A[rightEnd] = temp[rightEnd];
}

