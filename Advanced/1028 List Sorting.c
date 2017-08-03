#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stuRecord
{
	char id[7];
	char name[9];
	int grade;
}Record;

void input(Record* records, int N);
void sort(Record* records, int N, int C);
int cmp1(const void* a, const void* b);
int cmp2(const void* a, const void* b);
int cmp3(const void* a, const void* b);
void output(Record* records, int N);

int main()
{
	int N, C;
	scanf("%d %d", &N, &C);

	Record* records = (Record*)malloc(sizeof(Record) * N);
	input(records, N);
	sort(records, N, C);
	output(records, N);
	return 0;
}

void input(Record* records, int N)
{
	for(int i = 0; i < N; i++)
		scanf("%s %s %d", records[i].id,
			records[i].name, &records[i].grade);
}

void sort(Record* records, int N, int C)
{
	switch(C)
	{
		case 1: qsort(records, N, sizeof(Record), cmp1); break;
		case 2: qsort(records, N, sizeof(Record), cmp2); break;
		case 3: qsort(records, N, sizeof(Record), cmp3); break;
	}
}

int cmp1(const void* a, const void* b)
{
	return strcmp((*(Record*)a).id, (*(Record*)b).id);
}

int cmp2(const void* a, const void* b)
{
    int value;
	if((value = strcmp((*(Record*)a).name, (*(Record*)b).name)))
        return value;
    else
        return cmp1(a, b);
}

int cmp3(const void* a, const void* b)
{
	int value;
	if((value = (*(Record*)a).grade - (*(Record*)b).grade))
        return value;
    else
        return cmp1(a, b);
}

void output(Record* records, int N)
{
	for(int i = 0; i < N; i++)
		printf("%s %s %d\n", records[i].id,
			records[i].name, records[i].grade);
}
