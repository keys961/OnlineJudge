#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long sequence[100000];
long long smaller[100000];// <= max
long long larger[100000];// >= min

vector<long long> res;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &sequence[i]);
	smaller[0] = sequence[0];
	larger[n - 1] = sequence[n - 1];
	for (int i = 1; i < n; i++)
	{
		if (sequence[i] > smaller[i - 1])
			smaller[i] = sequence[i];
		else
			smaller[i] = smaller[i - 1];

		if (sequence[n - 1 - i] < larger[n - i])
			larger[n - 1 - i] = sequence[n - 1 - i];
		else
			larger[n - 1 - i] = larger[n - i];
	}
	for (int i = 0; i < n; i++)
	{
		if (smaller[i] == sequence[i] && larger[i] == sequence[i])
			res.push_back(sequence[i]);
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	if (res.size()) 
	{
		for (int i = 0; i < res.size() - 1; i++)
			printf("%ld ", res[i]);
		printf("%ld", res.back());
	}
	printf("\n");
	return 0;
}