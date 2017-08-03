#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<int> position;
int hashtable[15000];

bool isPrime(int n);
int nextPrime(int n);
void h(int num, int size);

int main(int argc, char const *argv[])
{
	for(int i = 0; i < 15000; i++)
		hashtable[i] = -1;
	int m, n, num;
	int size;
	scanf("%d %d", &m, &n);
	size = nextPrime(m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		h(num, size);
	}
	printf("%d", position[0]);
	for(int i = 1; i < n; i++)
	{
		if(position[i] == -1)
			printf(" -");
		else
			printf(" %d", position[i]);
	}
	printf("\n");
	return 0;
}

int nextPrime(int n)
{
	while(!isPrime(n++));
	return --n;
}

bool isPrime(int n)
{
	if(n == 1)
		return false;
	if(n == 2 || n == 3)
		return true;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

void h(int num, int size)
{
	int index, count = 0;
	int firstIndex = num % size;
	if(hashtable[firstIndex] == -1)
	{
		hashtable[firstIndex] = num;
		position.push_back(firstIndex);
		return;
	}
	index = firstIndex;
	while(hashtable[index] != -1)
	{
		count++;
		index = (firstIndex + count * count) % size;
		if(index == firstIndex)
		{
			position.push_back(-1);
			return;
		}
	}
	hashtable[index] = num;
	position.push_back(index);
}