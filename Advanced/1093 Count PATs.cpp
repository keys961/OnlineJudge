#include <cstdio>
#include <cstring>

using namespace std;
//DP
#define MOD 1000000007

char str[100001];
int pNum[100001] = {0};
int tNum[100001] = {0};

long getPATNum(int length);

int main(int argc, char const *argv[])
{
	scanf("%s", str);
	printf("%ld\n", getPATNum(strlen(str)));
	return 0;
}

long getPATNum(int length)
{	//Use DP
	long sum = 0;
	if(str[0] == 'P')
		pNum[0] = 1;
	if(str[length - 1] == 'T')
		tNum[length - 1] = 1;
	for(int i = 1; i < length; i++)
	{
		pNum[i] = str[i] == 'P' ? pNum[i - 1] + 1 : pNum[i - 1];
		tNum[length - 1 - i] = str[length - 1 - i] == 'T' ? tNum[length - i] + 1 :
			tNum[length - i];
	}
	for(int i = 0; i < length; i++)
	{
		if(str[i] == 'A')
			sum = (sum + pNum[i] * tNum[i]) % MOD;
	}
	return sum;
}