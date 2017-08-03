#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

bool isPrime(int n);
int nextPrime(int n);

int main()
{
    int  prime = 1;
    long num;
    scanf("%ld", &num);
    map<int, int> factors;
    if(num == 1 || isPrime(num))
        printf("%ld=%ld\n", num, num);
    else
    {
        printf("%ld=", num);
        while(num >= prime)
        {
            prime = nextPrime(prime);
            while (num % prime == 0)
            {
                if (factors.find(prime) == factors.end())
                    factors.insert(pair<int, int>(prime, 1));
                else
                    factors[prime]++;
                num /= prime;
            }
        }
        map<int, int>::iterator it = factors.begin();

        for(; ; )
        {
            printf("%d", it->first);
            if(it->second > 1)
                printf("^%d", it->second);
            if(++it != factors.end())
                printf("*");
            else
            {
                printf("\n");
                break;
            }
        }
    }
    return 0;
}

bool isPrime(int n)
{
    if(n == 1)
        return false;
    if(n == 2 || n == 3)
        return true;
    //int upbound = (int)sqrt(n);
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int nextPrime(int n)
{
    int res = ++n;
    while(!isPrime(res++));
    return --res;
}

