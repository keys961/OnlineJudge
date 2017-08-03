#include <cstdio>

using namespace std;

double sequence[100000];

double solve(int n);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lf", &sequence[i]);
	printf("%.2lf\n", solve(n));
	return 0;
}

double solve(int n)
{
	double result = 0.0;
	for(int i = 0; i < n; i++)
		result += sequence[i] * (i + 1) * (n - i);
	return result;
}