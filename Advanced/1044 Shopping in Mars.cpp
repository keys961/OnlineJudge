#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct result
{
	int begin;
	int end;
}Result;

int chain[100001] = {0, };
int minDiff = 0x7fffffff;
vector<Result> resList;

void input(int n);
void solve(int n, int m);

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d %d", &N, &M);
	input(N);
	solve(N, M);
	for(int i = 0; i < resList.size(); i++)
		printf("%d-%d\n", resList[i].begin, resList[i].end);
	return 0;
}

void input(int n)
{
	for(int i = 1; i <= n; i++)
		scanf("%d", &chain[i]);
}

void solve(int n, int m)
{
	int front = 1, tail = 1;
	int sum = 0, diff;
	Result res;
	while(tail <= n)
	{
		while(front <= n + 1)
		{
			if(sum >= m)
			{
				//front--;
				diff = sum - m;
				res.end = front - 1; res.begin = tail;
				if(diff < minDiff)
				{
					minDiff = diff;
					resList.clear();
					resList.push_back(res);
				}
				else if(diff == minDiff)
					resList.push_back(res);
				break;
			}
			if(front > n)
				break;
			sum += chain[front++];
		}
		sum -= chain[tail++];
	}
}