#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    long long temp;
    while(b)
    {    
        temp = b;
       	b = a % b;
       	a = temp;
   	}
   	return a;
}
long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}

struct Fraction
{
	long long numerator;
	long long denominator;
	long long integer;
	Fraction(long long numerator, long long denominator)
	{
		long long a = numerator;
		long long b = denominator;
		long long c = gcd(a, b);
		this->numerator = a / c;
		this->denominator = b / c;
		this->integer = this->numerator / this->denominator;
		this->numerator -= this->integer * this->denominator;
	}
	Fraction(){numerator = 0; denominator = 1; integer = 0;}
	
};

Fraction add(Fraction& a, Fraction& b);

Fraction fractions[100];

int main(int argc, char const *argv[])
{
	int n;
	long long a, b;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &a, &b);
		fractions[i] = Fraction(a, b);
	}
	Fraction res;
	for(int i = 0; i < n; i++)
		res = add(res, fractions[i]);
	if(res.integer == 0 && res.numerator == 0)
		printf("0");
	if(res.integer != 0)
		printf("%lld", res.integer);
	if(res.numerator != 0 && res.integer != 0)
		printf(" %lld/%lld", res.numerator, res.denominator);
	else if(res.numerator != 0 && res.integer == 0)
		printf("%lld/%lld", res.numerator, res.denominator);
	printf("\n");
	return 0;
}

Fraction add(Fraction& a, Fraction& b)
{	
	long long denominator = lcm(a.denominator, b.denominator);
	long long numerator = denominator / a.denominator * a.numerator + 
		denominator / b.denominator * b.numerator;
	Fraction c = Fraction(numerator, denominator);
	c.integer += (a.integer + b.integer);
	return c; 
}
