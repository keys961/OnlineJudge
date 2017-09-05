#include <cstdio>
#include <cmath>

using namespace std;

int board[1001];

bool isValid(int index, int n);

int main(int argc, char const *argv[])
{
    int k, n;
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        bool flag = true;
        scanf("%d", &n);
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &board[j]);
            if(flag)
                flag = isValid(j, n);
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

bool isValid(int index, int n)
{
    if(index == 1)
        return true;
    for(int i = 1; i < index; i++)
    {
        if(board[i] == board[index])
            return false;
        if(abs(index - i) == abs(board[index] - board[i]))
            return false;
    }
    return true;
}