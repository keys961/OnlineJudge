#include <cstdio>
#include <algorithm>

using namespace std;

int sequence[100000];

int getMinS(int n);

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &sequence[i]);
	sort(sequence, sequence + n);
	printf("%d %d\n", n % 2 == 0 ? 0 : 1, getMinS(n));
	return 0;
}

int getMinS(int n)
{
	int totalSum = 0;
	int halfSum = 0;
	for (int i = 0; i < n; i++)
	{
		totalSum += sequence[i];
		if (i < n / 2)
			halfSum += sequence[i];
	}
	return totalSum - 2 * halfSum;
}