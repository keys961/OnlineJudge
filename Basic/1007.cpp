#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

int sushu(int k)
{
    int j;
    for(j=2;j<=sqrt(k);j++)
        if(k%j==0)
            return 0;
    return 1;
}

int main()
{
    int i,j,n,x,y,count;
    x = 2;
    y = 3;
    cin>>n;
    count = 0;
    for(i=4;i<=n;i++)
    {
        if(sushu(i))
        {
            x = y;
            y = i;
            if(y-x == 2)
                count++;
        }
    }
    cout<<count<<endl;
    system("pause");
    return 0;
}