#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

map<char, int> shop;
map<char, int> require;

void stat(char* s, int flag);
int missing();

int main(int argc, char const *argv[])
{
    char s1[1001], s2[1001];
    scanf("%s %s", s1, s2);
    stat(s1, 0); stat(s2, 1);
    int missingNum = missing();
    if(missingNum > 0)
        printf("No %d\n", missingNum);
    else
        printf("Yes %d\n", strlen(s1) - strlen(s2));

    return 0;
}

void stat(char* s, int flag)
{
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(!flag)
            shop[s[i]]++;
        else
            require[s[i]]++;
    }
}

int missing()
{
    int flag = 0;
    auto it = require.begin();
    for(; it != require.end(); it++)
    {
        it->second -= shop[it->first];
        if(it->second > 0)
            flag += it->second;
    }
    return flag;
}