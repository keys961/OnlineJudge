#include <stdio.h>
#include <stdlib.h>
//Greedy Algorithm
using namespace std;

int coupon[100000] = {0,};
int product[100000] = {0,};

int solve(int NC, int NP);
int compare(const void* a , const void *b)
{
	return *(int*)b - *(int*)a;
}

int main(int argc, char const *argv[])
{
	int NC, NP;
	scanf("%d", &NC);
	for(int i = 0; i < NC; i++)
		scanf("%d", &coupon[i]);
	scanf("%d", &NP);
	for(int i = 0; i < NP; i++)
		scanf("%d", &product[i]);
	printf("%d\n", solve(NC, NP));
	return 0;
}

int solve(int NC, int NP)
{
	qsort(coupon, NC, sizeof(int), compare);
	qsort(product, NP, sizeof(int), compare);

	int res = 0;
	int frontC = 0, frontP = 0;
	int tailC = NC - 1, tailP = NP - 1;
	while(frontC < NC && frontP < NP)
	{
		if(coupon[frontC] * product[frontP] > 0)
			res += coupon[frontC++] * product[frontP++];
		else 
			break;
	}
	while(tailC >= frontC && tailP >= frontP)
	{
		if(coupon[tailC] * product[tailP] > 0)
			res += coupon[tailC--] * product[tailP--];
		else 
			break;
	}
	return res;
}