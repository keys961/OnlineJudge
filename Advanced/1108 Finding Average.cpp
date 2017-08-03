#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 110;
int n;
char str[maxn];
double result = 0;
bool flag = true;
double a[maxn];
int j = 0;

bool isLegal(int len)
{
	double result1 = 0,result2 = 0;
	int found = 0;
	int count = 0;
	int low = -1;
	for(int i = 0;i<len;i++)
	{
		if(str[i] == '.')
		{
			if(i == 0)
			{
				flag = false;
			}
			low = i;
			break;
		}
		else if(str[i] == '-')
		{
			if(i == 0)
			{
				found = 1;
			}
			else
			{
				found = 0;
				flag = false;
				break;
			}
		}
		else if(str[i] >= '0' && str[i] <= '9')
		{
			result1 = result1 * 10 + str[i] - '0';
			low = i;
		}
		else
		{
			flag = false;
			break;
		}
	}
	if(flag)
	{
		for(int i = low + 1;i<len;i++)
		{
			if(!(str[i] >= '0' && str[i] <= '9'))
			{
				flag = false;
				return false;
			}
			else
			{
				result2 = result2 * 10 + str[i] - '0';
				count++;
			}
		}
	}
	else
	{
		flag = false;
		return false;
	}
	if(flag)
	{
		if(count >= 3)
		{
			flag = false;
			return false;
		}
		if(count > 0)
			result2 = result2 * pow(0.1,count);
		result = result1 + result2;
		if(found == 1)
			result = -result;
		if(abs(result) > 1000)
		{
			flag = false;
			return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		flag = true;
		int l = strlen(str);
		if(isLegal(l))
		{
			a[j++] = result;
		}
		else
		{
			printf("ERROR: %s is not a legal number\n",str);
		}
	}
	if(j == 0)
	{
		printf("The average of 0 numbers is Undefined");
	}
	else if(j == 1)
	{
		printf("The average of 1 number is %.2lf",a[0]);
	}
	else
	{
		double x = 0;
		for(int i=0;i<j;i++)
		{
			x = x + a[i];
		}
		x = x / j;
		printf("The average of %d numbers is %.2lf",j,x);
	}
	return 0;
}
