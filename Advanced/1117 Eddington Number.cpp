#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sequence;

bool compare(int a, int b)
{
    return a > b;
}

int getE(int n);

int main(int argc, char const *argv[])
{
    int n, num;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        sequence.push_back(num);
    }
    sort(sequence.begin(), sequence.end(), compare);
    printf("%d\n", getE(n));
    return 0;
}

int getE(int n)
{
    int day = 0;
    for(int i = 0; i < n; i++)
    {
        if(sequence[i] > ++day + 1)
            continue;
        if(sequence[i] == day + 1)
            break;
        else
        {
            day--;
            break;
        }
    }
    return day;
}