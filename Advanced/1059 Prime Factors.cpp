#include <cstdio>
#include <map>

using namespace std;

map<long long, long long> factors;

bool isPrime(long long number);
long long nextPrime(long long number);
void getPrimeFactors(long long number);

int main()
{
	long long number;
	scanf("%lld", &number);

	if (number == 1 || isPrime(number)) 
	{
		printf("%ld=%ld\n", number, number);
		return 0;
	}

	getPrimeFactors(number);

	printf("%ld=", number);
	auto it = factors.begin();
	printf("%ld", it->first);
	if (it->second > 1)
		printf("^%d", it->second);
	it++;
	for (; it != factors.end(); it++)
	{
		printf("*%ld", it->first);
		if (it->second > 1)
			printf("^%d", it->second);
	}
	printf("\n");
	return 0;
}

bool isPrime(long long number)
{
	if (number == 1)
		return false;
	if (number == 2 || number == 3)
		return true;

	for (long long i = 2; i * i <= number; i++)
		if (number % i == 0)
			return false;
	return true;
}

long long nextPrime(long long number)
{
	if (number == 2)
		return 3;
	number += 2;
	while (!isPrime(number))
		number += 2;
	return number;
}

void getPrimeFactors(long long number)
{
	long long factor = 2;
	while (number > 1)
	{
		while (number % factor == 0)
		{
			factors[factor]++;
			number /= factor;
		}
		factor = nextPrime(factor);
	}
}
