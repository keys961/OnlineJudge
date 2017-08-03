#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(int n);
char getDigit(int n);

int main(int argc, char const *argv[])
{
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	char* cr,* cg,* cb;
	cr = convert(r);
	cg = convert(g);
	cb = convert(b);
	printf("#%s%s%s\n", cr, cg, cb);
	return 0;
}

char* convert(int n)
{
	char digit;
	char* digits = (char*)malloc(sizeof(char) * 3);
	int i = 1;
	digits[2] = 0;
	while(n)
	{
		digit = getDigit(n % 13);
		digits[i--] = digit;
		n /= 13;
	}
	if(i == 1)
		digits[i--] = '0';
	if(i == 0)
		digits[i] = '0';
	return digits;
}

char getDigit(int n)
{
	if(n < 10)
		return n + '0';
	else
		return n - 10 + 'A';
}