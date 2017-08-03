#include <stdio.h>
#include <stdlib.h>
struct Player
{
    int teamNumber;
    int playerNumber;
    int score;
};

int GetSum(int teamID, struct Player *players, int N)
{
    int i;
    int sum = 0;
    for(i=0;i<N;i++)
    {
        if(players[i].teamNumber == teamID)
            sum+=players[i].score;
    }
    return sum;
}
int main()
{
    int N;
    int i;
    scanf("%d",&N);
    struct Player players[N];


    for(i=0;i<N;i++)
    {
        scanf("%d-%d %d",&players[i].teamNumber,&players[i].playerNumber,&players[i].score);
    }
    int Max=GetSum(players[0].teamNumber,players,N);
    int MaxID=players[0].teamNumber;
    for(i=0;i<N;i++)
    {
        if(players[i].teamNumber==MaxID)
            continue;
        if(GetSum(players[i].teamNumber,players,N)>Max)
        {
            Max=GetSum(players[i].teamNumber,players,N);
            MaxID = players[i].teamNumber;
        }
    }
    printf("%d %d\n",MaxID,Max);
    return 0;
}