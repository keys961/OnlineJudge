#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student Student;
struct student
{
	char name[11];
	char id[11];
	//char gender;
	int grade;
};

void input(Student* maleStu, Student* femaleStu, int* countMale, int* countFemale);
int cmp(const void *a, const void *b);

int main()
{
	Student maleStu[101];
	Student femaleStu[101];
	int countMale = 0, countFemale = 0;

	input(maleStu, femaleStu, &countMale, &countFemale);

	if(countFemale == 0)
		printf("Absent\n");
	else
	{
		qsort(femaleStu, countFemale, sizeof(Student), cmp);
		printf("%s %s\n", femaleStu[countFemale - 1].name,
				 femaleStu[countFemale - 1].id);
	}

	if(countMale == 0)
		printf("Absent\n");
	else
	{
		qsort(maleStu, countMale, sizeof(Student), cmp);
		printf("%s %s\n", maleStu[0].name, maleStu[0].id);
	}

	if(countMale == 0 || countFemale == 0)
		printf("NA\n");
	else
		printf("%d\n", femaleStu[countFemale - 1].grade
			 - maleStu[0].grade);

	return 0;
}

void input(Student* maleStu, Student* femaleStu, int* countMale, int* countFemale)
{
	int N;
	char name[11];
	char id[11];
	char gender;
	int grade;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		scanf("%s %c %s %d", name, &gender, id, &grade);
		if(gender == 'M')
		{
			strcpy(maleStu[*countMale].name, name);
			strcpy(maleStu[*countMale].id, id);
			maleStu[*countMale].grade = grade;
			(*countMale)++;
		}
		else
		{
			strcpy(femaleStu[*countFemale].name, name);
			strcpy(femaleStu[*countFemale].id, id);
			femaleStu[*countFemale].grade = grade;
			(*countFemale)++;
		}
	}

}

int cmp(const void *a, const void *b)
{
	return (*(Student*)a).grade - (*(Student*)b).grade;
}