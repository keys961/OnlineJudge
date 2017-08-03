#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int N, n1, n2;
	int i, j;
	char str[81];
	scanf("%s", str);
	N = strlen(str);
	n1 = (N + 2)/3;
	n2 = N + 2 - 2*n1;
	for(i = 0, j = N - 1; i < n1 - 1; i++, j--)
	{
		printf("%c", str[i]);
		for(int k = 0; k < n2 - 2; k++)
			printf(" ");
		printf("%c\n", str[j]);
	}
	for(; i <= j; i++)
		printf("%c", str[i]);
	printf("\n");
	return 0;
}