

#include <stdio.h>
#include <string.h>
int index[6][10000];

void Search(char s,char *string)
{
    int i=0;
    char *p = string;
    switch(s)
    {
        case 'P':
            while((p=strchr(p,s))!=NULL&&*p)
            {
                index[0][i]=p-string;
                i++;
                p++;
            }break;
        case 'A':
            while((p=strchr(p,s))!=NULL&&*p)
            {
                index[1][i]=p-string;
                i++;
                p++;
            }break;
        case 'T':
            while((p=strchr(p,s))!=NULL&&*p)
            {
                index[2][i]=p-string;
                i++;
                p++;
            }break;
        case 'e':
            while((p=strchr(p,s))!=NULL&&*p)
            {
                index[3][i]=p-string;
                i++;
                p++;
            }break;
        case 's':
            while((p=strchr(p,s))!=NULL&&*p)
            {
                index[4][i]=p-string;
                i++;
                p++;
            }break;
        case 't':
            while((p=strchr(p,s))!=NULL&&*p)
            {
                index[5][i]=p-string;
                i++;
                p++;
            }break;
        default: break;
    }
}

int main()
{
    char String[10001];
    int i,j;
    gets(String);
    for(i=0;i<6;i++)
        for(j=0;j<10000;j++)
            index[i][j] = -1;
    Search('P',String);
    Search('A',String);
    Search('T',String);
    Search('e',String);
    Search('s',String);
    Search('t',String);
    for(j=0;j<10000;j++)
    {
        for(i=0;i<6;i++)
        {
            if(index[i][j]!=-1)
            {
                putchar(String[index[i][j]]);
            }
        }
    }
    printf("\n");
    return 0;
}