#include <cstdio>

using namespace std;

int array[100000];
int table[100000];
bool visited[100000] = {false};

void getCount(int n);

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        table[array[i]] = i;
    }
    getCount(n);
    return 0;
}

void getCount(int n)
{
    int s = 0, k = 0;
    int next;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            if(table[i] != i)
            {
                next = table[i];
                while(!visited[next])
                {
                    visited[next] = true;
                    next = table[next];
                }
                k++;//Multi-element loop
            }
            else
                s++;//Single-element loop
        }
    }
    if(array[0] == 0)
        printf("%d\n", n - s + k);
    else if(s == k)
        printf("0\n");
    else
        printf("%d\n", n - s + k - 2);
}