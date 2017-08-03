#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char days[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(int argc, char const *argv[])
{
	int day, hour, minute;
	int flag = 0;
	char str1[101];
	char str2[101];
	char str3[101]; 
	char str4[101];

	scanf("%s%s%s%s", str1, str2, str3, str4);
	
	for(int i = 0; str1[i] && str2[i]; i++)
	{
		if(str1[i] == str2[i])
		{
			if(flag == 0 && str1[i] >= 'A' && str1[i] <= 'G')
			{
				day = str1[i] - 'A';
				flag = 1;
			}
			else if(flag == 1 && str1[i] >= 'A' && str1[i] <= 'N' )
			{
				hour = str1[i] - 'A' + 10;
				break;
			}
			else if(flag == 1 && str1[i] >= '0' && str1[i] <= '9' )
			{
				hour = str1[i] - '0';
				break;
			}
		}
	}
	for(int i = 0; str3[i] && str4[i]; i++)
	{
		if(str3[i] == str4[i] && ((str3[i] >= 'A' && str3[i] <= 'Z' )||(str3[i] >= 'a' && str3[i] <= 'z')))
		{
			minute = i;
			break;
		}
	}
	printf("%s %02d:%02d\n", days[day], hour, minute);
	return 0;
}

