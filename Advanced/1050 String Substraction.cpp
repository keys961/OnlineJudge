#include <iostream>
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
    char s[10001] = {0};
    map<char, int> charSet;
    char c;
    gets(s);
    while((c = getchar()) != '\n')
        charSet[c] = 1;

    for(int i = 0; s[i]; i++)
        if(charSet[s[i]] != 1)
            printf("%c", s[i]);
    printf("\n");
    return 0;
}
