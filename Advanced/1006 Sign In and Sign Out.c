#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
	char id[16];
	long signInTime;
	long signOutTime;
}Person;

int compareIn(const void* a, const void* b);
int compareOut(const void* a, const void* b);

int main()
{
	int n;
	int hour, minute, second;
	scanf("%d", &n);
	Person roomPerson[n];

	for(int i = 0; i < n; i++)
	{
		scanf("%s", roomPerson[i].id);
		scanf("%d:%d:%d", &hour, &minute, &second);
		roomPerson[i].signInTime = 3600 * hour + 60 * minute + second;
		scanf("%d:%d:%d", &hour, &minute, &second);
		roomPerson[i].signOutTime = 3600 * hour + 60 * minute + second;
	}

	qsort(roomPerson, n, sizeof(Person), compareIn);
	printf("%s ", roomPerson[0].id);
	qsort(roomPerson, n, sizeof(Person), compareOut);
	printf("%s\n", roomPerson[0].id);
	return 0;
}

int compareIn(const void* a, const void* b)
{
	return (*(Person*)a).signInTime - (*(Person*)b).signInTime;
}

int compareOut(const void* a, const void* b)
{
	return (*(Person*)b).signOutTime - (*(Person*)a).signOutTime;
}