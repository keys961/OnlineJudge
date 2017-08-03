#include <stdio.h>

int isPrime(int n);
int getReverse(int n, int d);

int main(int argc, char const *argv[])
{
	int N, D;
	while(1)
	{
		scanf("%d", &N);
		if(N < 0)
			break;
		scanf("%d", &D);
		if(isPrime(N) && isPrime(getReverse(N, D)))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

int isPrime(int n)
{
	if(n == 1)
		return 0;
	if(n == 2 || n == 3)
		return 1;
	if(n % 6 != 1 && n % 6 != 5)
		return 0;
	for(int i = 5; i * i <= n; i += 6)
		if(n % i == 0 || n % (i + 2) == 0)
			return 0;
	return 1;
}

int getReverse(int n, int d)
{
	int res = 0;
	while(n)
	{
		res = res * d + (n % d);
		n /= d;
	}
	return res;
}