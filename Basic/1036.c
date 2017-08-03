#include <stdio.h>
#include <string.h>

int main()
{
    int n,i,j;
    int line,row;// hang lie
    char ch;
    scanf("%d %c",&n,&ch);
    row=n;
    if(n%2!=0)
    {
        line = n/2+1;
    }
    else
        line = n/2;

    for(i=0;i<line;i++)
    {
        for(j=0;j<row;j++)
        {
            if(i==0||i==line-1)
            {
                printf("%c",ch);
            }
            else
            {
                if(j==0||j==row-1)
                    printf("%c",ch);
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}