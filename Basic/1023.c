#include <stdio.h>
#include <string.h>
int main()
{
    int num[10],count = 0;
    int i;
    int j=0;
    char number[51]={0,};
    char temp;
    for(i=0;i<10;i++)
    {
        scanf("%d",&num[i]);
        count += num[i];
    }
    for(i=0;i<=9;i++)
    {
        while(num[i]!=0)
        {
            number[j] = i+'0';
            j++;
            num[i]--;
        }
    }
    if(number[0]=='0')
    {
        for(i=0;i<count;i++)
        {
            if(number[i]!='0')
            {
                temp = number[i];
                number[i]=number[0];
                number[0]=temp;
                break;
            }
        }
    }
    puts(number);
    return 0;
}