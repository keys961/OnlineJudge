#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,times;
    int i,j;
    scanf("%d %d",&n,&times);
    int list[n+1];

    for(i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }

    for(i=1;i<=times;i++)
    {
        for(j=n;j>=1;j--)
        {
            list[j]=list[j-1];
        }
        list[0]=list[n];
    }

    for(i=0;i<n-1;i++)
    {
        printf("%d ",list[i]);
    }
    printf("%d\n",list[n-1]);

    return 0;
}