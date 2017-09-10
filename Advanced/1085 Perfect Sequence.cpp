#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long sequence[100000];

int getSequenceLength(int n, long long p);

int main()
{
    int n;
    long long p;
    scanf("%d %lld", &n, &p);
    for (int i = 0; i < n; i++)
        scanf("%lld", &sequence[i]);

    sort(sequence, sequence + n);
    printf("%d\n", getSequenceLength(n, p));
    return 0;

}

int getSequenceLength(int n, long long p)
{
    int maxLen = 0;
    int ptr1 = 0, ptr2 = 0; //2ptr
    
    while (ptr2 < n)
    {
        while (ptr2 < n && sequence[ptr2] * 1.0 / sequence[ptr1] <= p)
            ptr2++;
        int len = ptr2 - ptr1;
        if (len > maxLen)
            maxLen = len;
        ptr1++;
    }
    return maxLen;
}