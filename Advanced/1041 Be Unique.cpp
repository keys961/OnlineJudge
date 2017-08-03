#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int visited[10001] = {0, };
vector<int> inputList;

int main(int argc, char const *argv[])
{
	int N, num;

	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		if(visited[num] == 0)//First
		{
			inputList.push_back(num);
			visited[num]++;
		}
		else
			visited[num]++;
	}
	for(int i = 0; i < inputList.size(); i++)
		if(visited[inputList[i]] == 1)
		{
			printf("%d\n", inputList[i]);
			return 0;
		}
	printf("None\n");
	return 0;
}