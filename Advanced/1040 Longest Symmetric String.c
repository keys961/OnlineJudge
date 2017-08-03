#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Brute algorithm
int longSymStr(char* str, int begin, int end);

int main(int argc, char const *argv[])
{
	int len;
	char str[1001];
	gets(str);
	len = strlen(str);
	printf("%d\n", longSymStr(str, 0, len - 1));
	return 0;
}

int longSymStr(char* str, int begin, int end)
{
	int max = 0;
	for(int i = 0; i <= end; i++)
	{
		for(int j = 0; i - j >= 0 && i + j <= end; j++)
		{
			if(str[i - j] != str[i + j])
				break;
			if(j * 2 + 1 > max)
				max = j * 2 + 1;
		}
		for(int j = 0; i - j >= 0 && i + j + 1 <= end; j++)
		{
			if(str[i - j] != str[i + j + 1])
				break;
			if(j * 2 + 2 > max)
				max = j * 2 + 2;
		}
	}
	return max;
}
