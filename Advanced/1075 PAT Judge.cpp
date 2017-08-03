#include <stdio.h>
#include <stdlib.h>

typedef struct user
{
	int id; //output: using %0md, m is the width
	int score[5];
	int sum;
	int pass;
	int flag;
}Student;

Student* InitializeUsers(int N);
int Compare(const void* a, const void *b);

int main()
{
	int N, K, M; //users problems submissions
	int user_id, problem_id, score;
	int fullScore[5];
	int rank = 0;
	int count = 0;
	int temp = 0;
	Student *user;
	scanf("%d %d %d", &N, &K, &M);
	user = InitializeUsers(N);
	for(int i = 0; i < K; i++)
		scanf("%d", &fullScore[i]);
	for(int i = 0; i < M; i++) //Input
	{
		scanf("%d %d %d", &user_id, &problem_id, &score);
		if(score > user[user_id - 1].score[problem_id - 1])
			user[user_id - 1].score[problem_id - 1] = score;
	}
	for(int i = 0; i < N; i++)//Get Sum
	{
		for(int j = 0; j < K; j++)
		{
			if(user[i].score[j] >= 0)
			{
				user[i].sum += user[i].score[j];
				user[i].flag = 1;
			}
			if(user[i].score[j] == fullScore[j])
				user[i].pass ++;
		}

	}
	qsort(user, N, sizeof(Student), Compare);
	for(int i = 0; i < N; i++)//Output
	{
	    if(user[i].flag == 0)
            continue;
		if(user[i].sum == temp)
			count++;
		else
		{
			rank += count + 1;
			count = 0;
		}
		temp = user[i].sum;
		printf("%d %05d %d", rank, user[i].id, user[i].sum);
		for(int j = 0; j < K - 1; j++)
			if(user[i].score[j] >= 0)
				printf(" %d", user[i].score[j]);
			else if(user[i].score[j] == -1)
				printf(" 0");
			else
				printf(" -");
		if(user[i].score[K - 1] >= 0)
			printf(" %d\n", user[i].score[K - 1]);
		else if(user[i].score[K - 1] == -1)
			printf(" 0\n");
		else
			printf(" -\n");
	}
	return 0;
}

Student* InitializeUsers(int N)
{
	Student *user = (Student*)malloc(sizeof(Student) * N);
	for(int i = 0; i < N; i++)
	{
		user[i].id = i + 1;
		for(int j = 0; j < 5; j++)
			user[i].score[j] = -2;
		user[i].sum = 0;
		user[i].pass = 0;
		user[i].flag = 0;
	}
	return user;
}

int Compare(const void* a, const void* b) //if return negative a is first, or b is first
{
	Student *userA = (Student*)a;
	Student *userB = (Student*)b;
	if(userA->sum < userB->sum)
		return 1;
	else if(userA->sum > userB->sum)
		return -1;
	else
		if(userA->pass < userB->pass)
			return 1;
		else if(userA->pass > userB->pass)
			return -1;
		else
			if(userA->id < userB->id)
				return -1;
			else
				return 1;
}
