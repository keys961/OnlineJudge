#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Contains(char *buy, char *sell) 
{
    //int i=0;
    char *p = NULL;
    while(*buy!=0)
    {
        if((p=strchr(sell,*buy))==NULL)
            return 0;
        *p='?';
        buy++;
    }
    return 1;
}

int main()
{
    //int count[2]={0,0};
    int i=0,j;
    char *q = NULL;
    char str[4][1001];
    gets(str[0]);
    gets(str[1]);
    strcpy(str[2],str[0]);
    strcpy(str[3],str[1]);
    //count[0] = strlen(str[0]);
    //count[1] = strlen(str[1]);
    if(Contains(str[1],str[0]))
    {
        printf("Yes %d\n",strlen(str[0])-strlen(str[1]));
    }
    else
    {
        for(j=0;str[3][j]!=0;j++)
            if(q=strchr(str[2],str[3][j]))
            {
                *q='?';
                i++;
            }
        printf("No %d\n",strlen(str[1])-i);
    }
    return 0;
}