#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;

typedef struct node
{
	char character;
	int next;
}Character;

map<int, Character> str;
int times[100000] = {0,};

void input(int n);

int main(int argc, char const *argv[])
{

	int N, firstAddr, secondAddr;
	scanf("%d %d %d", &firstAddr, &secondAddr, &N);
	input(N);
	//First traversal
	for(; firstAddr != -1; firstAddr = str[firstAddr].next)
		times[firstAddr]++;
	//Second traversal
	for(; secondAddr != -1; secondAddr = str[secondAddr].next)
	{
		times[secondAddr]++;
		if(times[secondAddr] > 1)
		{
			printf("%.5d\n", secondAddr);
			return 0;
		}
	}

	printf("-1\n");
	

	return 0;
}

void input(int n)
{
	int addr;
	Character node;
	for(int i = 0; i < n; i++)
	{
		scanf("%d %c %d", &addr, &node.character, &node.next);
		str[addr] = node;
	}
}