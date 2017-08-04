#include <cstdio>
#include <set>

using namespace std;

set<int> friendId;

int getFriendId(int n);

int main(int argc, char const *argv[])
{
    int n, num;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        friendId.insert(getFriendId(num));
    }
    printf("%d\n", friendId.size());
    auto it = friendId.begin();
    printf("%d", *it++);
    for(; it != friendId.end(); it++)
        printf(" %d", *it);
    printf("\n");
    return 0;
}

int getFriendId(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}