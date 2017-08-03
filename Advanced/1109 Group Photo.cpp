#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Person
{
    char name[9];
    int height;
};

Person people[10000];
Person group[100][5000];

int getRowNum(int n, int row)
{
    return n / row;
}

bool compare(Person a, Person b)
{
    if(a.height == b.height)
        return strcmp(a.name, b.name) < 0;
    return a.height > b.height;
}

void togroup(int n, int row, int rowNum);

int main(int argc, char const *argv[])
{
    int n, row, rowNum, lastNum;
    scanf("%d %d", &n, &row);
    rowNum = getRowNum(n, row);
    for(int i = 0; i < n; i++)
        scanf("%s %d", people[i].name, &people[i].height);
    sort(people, people + n, compare);
    togroup(n, row, rowNum);
    lastNum = n - rowNum * (row - 1);
    for(int i = 0; i <= row - 1; i++)
    {
        if(i == 0)
        {
            for(int j = 0; j < lastNum - 1; j++)
                printf("%s ", group[i][j].name);
            printf("%s", group[i][lastNum - 1].name);
        }
        else
        {
            for(int j = 0; j < rowNum - 1; j++)
                printf("%s ", group[i][j].name);
            printf("%s", group[i][rowNum - 1].name);
        }
        printf("\n");
    }
    return 0;
}

void togroup(int n, int row, int rowNum)
{
    int centerPos, pos;
    int startPerson = 0, temp, sign;
    for(int i = 0; i < row; i++, startPerson += rowNum)
    {
        temp = 1; sign = 1;
        if(i == 0)
        {
            rowNum = n - (row - 1) * rowNum;
            centerPos = rowNum / 2;
        }
        else
        {
            rowNum = n / row;
            centerPos = rowNum / 2;
        }
        for(int j = startPerson; j < startPerson + rowNum; j++)
        {
            pos = temp * sign / 2 + centerPos;
            group[i][pos] = people[j];
            temp++; sign = -sign;
        }
    }
}