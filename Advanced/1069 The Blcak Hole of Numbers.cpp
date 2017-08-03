#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int num)
{
	return (num == 1111) || (num == 2222) || (num == 3333) ||
		(num == 4444) || (num == 5555) || (num == 6666) ||
		(num == 7777) || (num == 8888) || (num == 9999);
}

int getIncrease(int num)
{
	int res = 0;
	vector<int> digit(4);
	for(int i = 0; i < 4; i++, num /= 10)
		digit[i] = num % 10;
	sort(digit.begin(), digit.end());
	for(int i = 3; i >= 0; i--)
		res = res * 10 + digit[i];
	return res;
}

int getDecrease(int num)
{
	int res = 0;
	vector<int> digit(4);
	for(int i = 0; i < 4; i++, num /= 10)
		digit[i] = num % 10;
	sort(digit.begin(), digit.end());
	for(int i = 0; i < 4; i++)
		res = res * 10 + digit[i];
	return res;
}

int main(int argc, char const *argv[])
{
	int num;
	int increase, decrease, result;
	scanf("%d", &num);
	if(check(num))
		printf("%04d - %04d = 0000\n", num, num);
	else
	{
		result = num;
		while((decrease = getIncrease(result)) - 
			(increase = getDecrease(result)) != 6174)
		{
			result = decrease - increase;
			printf("%04d - %04d = %04d\n", decrease, increase, result);
		}
		printf("%04d - %04d = 6174\n", decrease, increase);
	}
	return 0;
}