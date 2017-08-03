#include <stdio.h>
#include <stdlib.h>

typedef struct person Person;
struct person
{
	int id;
	int virtueGrade;
	int talentGrade;
	int totalGrade;
	int sort; //1, Sage 2,Noble 3,Fool 4,Small
};

int input(Person* people, int N, int L, int H);
int cmp(const void* a, const void* b);

int main()
{
	int N, L, H, cnt;
	scanf("%d %d %d", &N, &L, &H);
	Person* people = (Person*)malloc(sizeof(Person) * N);
	cnt = input(people, N, L, H);
	qsort(people, cnt, sizeof(Person), cmp);

	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
		printf("%d %d %d\n", people[i].id, people[i].virtueGrade, people[i].talentGrade);
	return 0;
}

int input(Person* people, int N, int L, int H)
{
	int id, virtueGrade, talentGrade;
	int cnt = 0;
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &id, &virtueGrade, &talentGrade);
		if(virtueGrade < L || talentGrade < L)
			continue;
		else
		{
			people[cnt].id = id;
			people[cnt].virtueGrade = virtueGrade;
			people[cnt].talentGrade = talentGrade;
			people[cnt].totalGrade = virtueGrade + talentGrade;
			if(virtueGrade >= H && talentGrade >= H)
				people[cnt].sort = 1;
			else if(virtueGrade >= H && (talentGrade >= L && talentGrade < H))
				people[cnt].sort = 2;
			else if((talentGrade >= L && talentGrade < H) &&
				 (virtueGrade >= L && virtueGrade < H) && (virtueGrade >= talentGrade))
				people[cnt].sort = 3;
			else
				people[cnt].sort = 4;
			cnt++;
		}
	}
	return cnt;
}

int cmp(const void* a, const void* b)
{
	Person p1 = *(Person*)a, p2 = *(Person*)b;
	if(p1.sort < p2.sort)
		return -1;
	else if(p1.sort > p2.sort)
		return 1;
	else
	{
		if(p1.totalGrade > p2.totalGrade)
			return -1;
		else if(p1.totalGrade < p2.totalGrade)
			return 1;
		else
		{
			if(p1.virtueGrade > p2.virtueGrade)
				return -1;
			else if(p1.virtueGrade < p2.virtueGrade)
				return 1;
			else
				return p1.id - p2.id;
		}
	}
}
