#include <stdio.h>
#include <string.h>
int Count(int A,int Da)
{
    int count = 0;
    while(A!=0)
    {
        if(A%10==Da)
            count++;
        A/=10;
    }
    return count;
}
int main()
{
    int A,B;
    int Da,Db;
    int countA,countB;
    int Pa=0,Pb=0;
    int i;
    scanf("%d %d %d %d",&A,&Da,&B,&Db);
    countA = Count(A,Da);
    countB = Count(B,Db);
    for(i=0;i<countA;i++)
    {
        Pa = Pa*10 + Da;
    }
    for(i=0;i<countB;i++)
    {
        Pb = Pb*10 + Db;
    }
    printf("%d\n",Pa+Pb);
    return 0;
}