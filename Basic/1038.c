#include <stdio.h>
#include <stdlib.h>
//1038 用键值对查找 O(1)
int main()
{
	int n,m,score,i;
	int check;
	int p[101] = {0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&score);
		p[score]++;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&check);
		if(i==m-1)
			printf("%d", p[check]);
		else
			printf("%d ", p[check]);
	}
	printf("\n");
	return 0;
}