#include <cstdio>

using namespace std;

long long getOnes(int n);
long long getOnesPerDigit(int n, int digit, int weight);

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    printf("%ld\n", getOnes(n));
    return 0;
}

long long getOnes(int n)
{
    long long res = 0;
    long long weight = 1;
    long long temp = n;
    while(temp != 0)
    {
        res += getOnesPerDigit(n, temp % 10, weight);
        temp /= 10;
        weight *= 10;
    }
    return res;
}

long long getOnesPerDigit(int n, int digit, int weight)
{
    if(digit == 0)
        return (n / (10 * weight)) * weight;
    if(digit == 1)
        return (n / (10 * weight)) * weight + n % weight + 1;
    return (n / (10 * weight) + 1) * weight;
}