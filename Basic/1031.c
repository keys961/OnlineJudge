#include <stdio.h>
//1031
int CalcZ(char *str);
int IsMatch(int z,char *str);

int main()
{
	int n;
	int i;
	int flag = 1;
	int z;
	char identity[19];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(identity);
		z = CalcZ(identity);
		if(IsMatch(z,identity)!=1)
		{
			puts(identity);
			flag=0;
		}
	}
	if(flag)
		printf("All passed\n");
	return 0;
}

int CalcZ(char *str)
{
	int weigh[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int sum = 0;
	int i;
	int z;
	for(i=0;i<17;i++)
		sum += (str[i]-'0')*weigh[i];
	z = (sum%11);
	return z;
}

int IsMatch(int z, char *str)
{
	char M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
	if(str[17]==M[z])
		return 1;
	return 0;
}
