#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	char name[11];
	char id[11];
	int grade;
}Student;

void input(Student* record, int N);
int cmp(const void* a, const void* b);
void find(Student* record, int N, int grade1, int grade2);

int main()
{
	int N, grade1, grade2;
	Student record[101];
	scanf("%d", &N);
	input(record, N);

	qsort(record, N, sizeof(Student), cmp);
	scanf("%d %d", &grade1, &grade2);
	find(record, N, grade1, grade2);

	return 0;
}

void input(Student* record, int N)
{
	for(int i = 0; i < N; i++)
		scanf("%s %s %d", record[i].name, 
			record[i].id, &record[i].grade);
}

int cmp(const void* a, const void* b)
{
	return (*(Student*)b).grade - (*(Student*)a).grade;
}

void find(Student* record, int N, int grade1, int grade2)
{
	int flag = 0;
	for(int i = 0; i < N; i++)
	{
		if(record[i].grade >= grade1 && record[i].grade <= grade2)
		{
			printf("%s %s\n", record[i].name, record[i].id);
			flag = 1;
		}
	}

	if(!flag)
		printf("NONE\n");
}