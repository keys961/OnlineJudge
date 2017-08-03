#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char num[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    char ch[100];
    int s[10];
    int i,n,first=1,sum=0;
    scanf("%s",ch);
    n=strlen(ch);
    for(i=0;i<n;i++)
        sum=sum+ch[i]-48;
    n=0;
    if(sum==0)
    {
        printf("zero");
        return 0;
    }
    while(sum>0)
    {
        s[n]=sum%10;
        sum=sum/10;
        n++;
    }
    for(i=n-1;i>=0;i--)
    {
        if(first)
        {
            printf("%s",num[s[i]]);
            first=0;
        }
        else printf(" %s",num[s[i]]);
    }
    system("pause");
    return 0;
}
