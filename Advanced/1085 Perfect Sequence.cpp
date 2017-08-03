#include <cstdio>
#include <algorithm>

using namespace std;

long sequence[100001]; //0 - n

int main(int argc, char const *argv[])
{
    int n, p;
    scanf("%d %d", &n, &p);
    for(int i = 0; i < n; i++)
        scanf("%ld", &sequence[i]);
    sort(sequence, sequence + n);
    int i;
    int maxLen = 0;
    for(i = 0; i < n; i++)
    {
        if(sequence[n - 1] <= p * sequence[i])
        {
            if(maxLen < n - i)
                maxLen = n - i;
            break;
        }
        int low = i, up = n - 1;
        int mid;
        while(low <= up)//Binary Search
        {
            mid = (low + up) / 2;
            if(sequence[mid] > p * sequence[i])
                up = mid - 1;
            else
                low = mid + 1;
        }
        if(low - i > maxLen)
            maxLen = low - i;
    }
    printf("%d\n", maxLen);
    return 0;
}