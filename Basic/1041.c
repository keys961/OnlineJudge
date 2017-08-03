#include <stdio.h>
#include <string.h>
struct Student
{
    char ID[14];
    int trySeat;
    int testSeat;
};
int main()
{
    int n,i,j;
    int searchNum, trySeat;
    scanf("%d",&n);
    struct Student students[1000];
    for(i=0;i<n;i++)
    {
        scanf("%s %d %d",students[i].ID,&students[i].trySeat,&students[i].testSeat);
    }
    scanf("%d",&searchNum);
    for(i=0;i<searchNum;i++)
    {
        scanf("%d",&trySeat);
        for(j=0;j<n;j++)
        {
            if(students[j].trySeat==trySeat)
                printf("%s %d\n",students[j].ID,students[j].testSeat);
        }
    }
    return 0;
}