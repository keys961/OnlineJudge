#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char id[7];
	int C;
	int M;
	int E;
	double A;
}Student;

typedef struct bestRank
{
	char subject;
	int rank;
}Rank;

Student* rankA, *rankC, *rankM, *rankE;

void input(Student* students, int N);
int cmpA(const void *a, const void *b);
int cmpC(const void *a, const void *b);
int cmpM(const void *a, const void *b);
int cmpE(const void *a, const void *b);
Rank getRank(int N, char* id, Student* students);


int main()
{
	Student* students = NULL;
	int N, M;
	char id[7];
	scanf("%d %d", &N, &M);
	students = (Student*)malloc(sizeof(Student) * N);
	input(students, N);
	//sort(students, N);

	Rank bestRank;
	for(int i = 0; i < M; i++)
	{
		scanf("%s", id);
		bestRank = getRank(N, id, students);
		if(bestRank.rank == 1<<30)
			printf("N/A\n");
		else
			printf("%d %c\n", bestRank.rank, bestRank.subject);
	}


	return 0;
}

void input(Student* students, int N)
{
	for(int i = 0; i < N; i++)
	{
		scanf("%s %d %d %d", students[i].id, &students[i].C,
			&students[i].M, &students[i].E);
		students[i].A = (students[i].C + students[i].M
			+ students[i].E) * 1.0 / 3;
	}
}

int cmpA(const void *a, const void *b)
{
	if((*(Student*)a).A - (*(Student*)b).A > 0)
		return -1;
	else
		return 1;
}

int cmpC(const void *a, const void *b)
{
	if((*(Student*)a).C - (*(Student*)b).C > 0)
		return -1;
	else
		return 1;
}

int cmpM(const void *a, const void *b)
{
	if((*(Student*)a).M - (*(Student*)b).M > 0)
		return -1;
	else
		return 1;
}

int cmpE(const void *a, const void *b)
{
	if((*(Student*)a).E - (*(Student*)b).E > 0)
		return -1;
	else
		return 1;
}

Rank getRank(int N, char* id, Student* students)
{
	Rank bestRank;
	int i;
	bestRank.subject = '-';
	bestRank.rank = 1<<30;
	int rank, count;
	double previousMark;
	//A
	qsort(students, N, sizeof(Student), cmpA);
	rankA = students;
	for(i = 0, rank = 0, count = 0, previousMark = 101; i < N; i++)
	{
		if(rankA[i].A < previousMark)
		{
			rank += count + 1;
			count = 0;
			previousMark = rankA[i].A;
		}
		else if(rankA[i].A == previousMark)
			count++;
		if(strcmp(id, rankA[i].id) == 0)
		{
			if(bestRank.rank > rank)
			{
				bestRank.rank = rank;
				bestRank.subject = 'A';
				break;
			}
		}
	}
	if(i == N)
        return bestRank;
    qsort(students, N, sizeof(Student), cmpC);
    rankC = students;
	for(i = 0, rank = 0, count = 0, previousMark = 101; i < N; i++)
	{
		if(rankC[i].C < previousMark)
		{
			rank += count + 1;
			count = 0;
			previousMark = rankC[i].C;
		}
		else if(rankC[i].C == previousMark)
			count++;
		if(strcmp(id, rankC[i].id) == 0)
		{
			if(bestRank.rank > rank)
			{
				bestRank.rank = rank;
				bestRank.subject = 'C';
				break;
			}
		}
	}
    qsort(students, N, sizeof(Student), cmpM);;
    rankM = students;
	for(i = 0, rank = 0, count = 0, previousMark = 101; i < N; i++)
	{
		if(rankM[i].M < previousMark)
		{
			rank += count + 1;
			count = 0;
			previousMark = rankM[i].M;
		}
		else if(rankM[i].M == previousMark)
			count++;
		if(strcmp(id, rankM[i].id) == 0)
		{
			if(bestRank.rank > rank)
			{
				bestRank.rank = rank;
				bestRank.subject = 'M';
				break;
			}
		}
	}
    qsort(students, N, sizeof(Student), cmpE);
    rankE = students;
	for(i = 0, rank = 0, count = 0, previousMark = 101; i < N; i++)
	{
		if(rankE[i].E < previousMark)
		{
			rank += count + 1;
			count = 0;
			previousMark = rankE[i].E;
		}
		else if(rankM[i].E == previousMark)
			count++;
		if(strcmp(id, rankE[i].id) == 0)
		{
			if(bestRank.rank > rank)
			{
				bestRank.rank = rank;
				bestRank.subject = 'E';
				break;
			}
		}
	}
	return bestRank;
}
