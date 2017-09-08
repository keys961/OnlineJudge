#include <cstdio>
#include <algorithm>

using namespace std;

long long coupons[100000];
long long products[100000];

bool compare(int a, int b)
{
	return a > b;
}

long long getMaxProfit(int nc, int np)
{
	int i = 0, j = 0;
	int ir = nc - 1, jr = np - 1;
	long long profit = 0;
	while (i < nc && j < np)
	{
		if (coupons[i] * products[j] > 0)
		{
			profit += coupons[i] * products[j];
			i++; j++;
		}
		else
			break;
	}
	while (ir >= i && jr >= j)
	{
		if (coupons[ir] * products[jr] > 0)
		{
			profit += coupons[ir] * products[jr];
			ir--; jr--;
		}
		else
			break;
	}
	return profit;
}

int main()
{
	int nc, np;
	scanf("%d", &nc);
	for (int i = 0; i < nc; i++)
		scanf("%lld", &coupons[i]);
	scanf("%d", &np);
	for (int i = 0; i < np; i++)
		scanf("%lld", &products[i]);

	sort(coupons, coupons + nc, compare);
	sort(products, products + np, compare);

	printf("%ld\n", getMaxProfit(nc, np));

	return 0;
}