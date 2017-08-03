#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    n *= m;
    int color;
    map<int, int> colors;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &color);
        if(colors.count(color) == 0)
            colors.insert(pair<int, int>(color, 1));
        else
            colors[color]++;
    }
    for(map<int, int>::iterator it = colors.begin(); it != colors.end(); it++)
    {
        if(it->second >  n / 2)
        {
            printf("%d\n", it->first);
            break;
        }
    }
    //system("pause");
    return 0;
}