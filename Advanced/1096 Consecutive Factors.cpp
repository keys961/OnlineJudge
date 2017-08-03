#include <cstdio>
#include <cmath>

using namespace std;

int start = 2, final = 2;

void getFactors(int num);

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    getFactors(num);
    printf("%d\n", final - start + 1);
    for(int i = start; i < final; i++)
        printf("%d*", i);
    printf("%d\n", final);
    return 0;
}

void getFactors(int num)
{
    start = final = num;
    int up = (int)sqrt(num);
    int tempStart, tempEnd; // Left close right open
    int temp;
    for(int i = 2; i <= up; i++)
    {
        tempStart = tempEnd = temp = i;
        while(num % temp == 0)
            temp *= ++tempEnd;
        if(tempEnd - tempStart > final - start + 1 ||
                (tempEnd - tempStart == final - start + 1 && tempStart < start))
        {
            start = tempStart;
            final = tempEnd - 1;
        }
    }
}