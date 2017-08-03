#include <stdio.h>
#include <string.h>

int main()
{
    long money[2][3]; //[0] P [1] A [2]tempP [3]tempA
    long moneyKnut[2];
    long change[3]={0,};//G.S.K
    scanf("%ld.%ld.%ld %ld.%ld.%ld",&money[0][0],&money[0][1],&money[0][2],&money[1][0],&money[1][1],&money[1][2]);
    moneyKnut[0]=money[0][0]*29*17+money[0][1]*29+money[0][2];
    moneyKnut[1]=money[1][0]*29*17+money[1][1]*29+money[1][2];
    change[2]=moneyKnut[1]-moneyKnut[0];
    if(change[2]>=0)
    {
        change[0] = change[2]/(29*17);
        change[2] -= change[0]*29*17;
        change[1] = change[2]/29;
        change[2] -= change[1]*29;
        printf("%ld.%ld.%ld\n",change[0],change[1],change[2]);
    }
    else
    {
        change[2]=-change[2];
        change[0] = change[2]/(29*17);
        change[2] -= change[0]*29*17;
        change[1] = change[2]/29;
        change[2] -= change[1]*29;
        printf("-%ld.%ld.%ld\n",change[0],change[1],change[2]);
    }
    return 0;
}