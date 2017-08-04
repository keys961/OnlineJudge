#include <cstdio>
#include <queue>

using namespace std;

priority_queue<double> q;

int getLength();

int main(int argc, char const *argv[])
{
    int n, val;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        q.push(-(double)val);
    }
    printf("%d\n", getLength());
    return 0;
}

int getLength()
{
    double len1, len2;
    while(q.size() > 1)
    {
        len1 = q.top();
        q.pop();
        len2 = q.top();
        q.pop();
        q.push((len1 + len2) / 2);
    }
    return (int)(-q.top());
}