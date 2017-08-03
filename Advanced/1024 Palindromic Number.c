#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* add(char* a, char* b);
char* reverse(char* a);

int main(int argc, char const *argv[])
{
	char* n = (char*)malloc(sizeof(char)*101);
	int k, i;
	char* rev;
	scanf("%s %d", n, &k);

	for(i = 0; i < k; i++)
	{
		rev = reverse(n);
		if(strcmp(rev, n) == 0)
			break;
		n = add(n, rev);
	}
	printf("%s\n", n);
	printf("%d\n", i);
	return 0;
}

char* reverse(char* a)
{
	int length = strlen(a);
	char* rev = (char*)malloc(sizeof(char)*(length + 1));
	rev[length] = 0;
	length = length - 1;
	for(int i = 0; i <= length; i++)
		rev[length - i] = a[i];
	return rev;
}

char* add(char* a, char* b)
{
	int digit, carry = 0;
	int i = strlen(a), j = strlen(b);
	int length = (i > j ? i : j) + 1;
	char* res = (char*)malloc(sizeof(char)*(length + 1));
	res[length--] = 0;
	i--, j--;

	while(i >= 0 && j >= 0)
	{
		digit = a[i--] - '0' + b[j--] - '0' + carry;
		if(digit >= 10)
			carry = 1;
		else carry = 0;
		digit = digit % 10;
		res[length--] = digit + '0';
	}
	while(i >= 0)
	{
		digit = a[i--] - '0' + carry;
		if(digit >= 10)
			carry = 1;
		else
			carry = 0;
		digit = digit % 10;
		res[length--] = digit + '0';
	}
	while(j >= 0)
	{
		digit = b[j--] - '0' + carry;
		if(digit >= 10)
			carry = 1;
		else
			carry = 0;
		digit = digit % 10;
		res[length--] = digit + '0';
	}
	if(carry)
		res[length--] = carry + '0';
	return &res[length + 1];
}
