#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tester
{
	char registrationNumber[14];
	int grade;
	int finalRank;
	int locationNumber;
	int localRank;
}Tester;

int input(int N, Tester* testers);
int cmp(const void* a, const void* b);
void getFinalRank(Tester* testers, int size);
void getLocalRank(Tester* testers, int size, int N);
void output(Tester* testers, int size);

int main()
{
	int N, size;
	Tester testers[30000];
	scanf("%d", &N);
	size = input(N, testers);

	qsort(testers, size, sizeof(Tester), cmp);
	getFinalRank(testers, size);
	getLocalRank(testers, size, N);
	printf("%d\n", size);
	output(testers, size);

	return 0;
}

int input(int N, Tester* testers)
{
	int K;
	int count = 0;
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &K);

		for(int j = count; j < K + count; j++)
		{
			scanf("%s %d", testers[j].registrationNumber
				, &testers[j].grade);
			testers[j].locationNumber = i;
		}

		count += K;
	}
	return count;
}

int cmp(const void* a, const void* b)
{
	Tester testerA = *(Tester*)a, testerB = *(Tester*)b;
	if((testerA.grade - testerB.grade) > 0)
		return -1;
	else if(testerA.grade - testerB.grade == 0)
	{
		if(strcmp(testerA.registrationNumber, testerB.registrationNumber) > 0)
			return 1;
		else
			return -1;
	}
	else
		return 1;
}

void getFinalRank(Tester* testers, int size)
{
	int rank = 0;
	int count = 0;
	int previousGrade = 101;

	for(int i = 0; i < size; i++)
	{
		if(testers[i].grade < previousGrade)
		{
			rank += count + 1;
			testers[i].finalRank = rank;
			count = 0;
			previousGrade = testers[i].grade;
		}
		else if(testers[i].grade == previousGrade)
		{
			testers[i].finalRank = rank;
			count++;
		}
	}
}

void getLocalRank(Tester* testers, int size, int N)
{
	int rank;
	int count;
	int previousGrade;

	for(int i = 1; i <= N; i++)
	{
		rank = count = 0;
		previousGrade = 101;
		for(int j = 0; j < size; j++)
		{
			if(testers[j].locationNumber == i)
			{
				if(testers[j].grade < previousGrade)
				{
					rank += count + 1;
					testers[j].localRank = rank;
					count = 0;
					previousGrade = testers[j].grade;
				}
				else if(testers[j].grade == previousGrade)
				{
					testers[j].localRank = rank;
					count++;
				}
			}
		}
	}
}

void output(Tester* testers, int size)
{
	for(int i = 0; i < size; i++)
		printf("%s %d %d %d\n", testers[i].registrationNumber,
			testers[i].finalRank, testers[i].locationNumber,
			testers[i].localRank);
}
