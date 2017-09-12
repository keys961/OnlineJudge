#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> finalRes;
int sum = 0;
int n, k, p;

void solve(int n, int num, vector<int>& factors);
int power(int i, int p)
{
    int res = 1;
    for(int j = 0; j < p; j++)
        res *= i;
    return res;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &n, &k, &p);
    vector<int> factors((unsigned int)k);
    solve(n, 0, factors);
    reverse(finalRes.begin(), finalRes.end());
    if(finalRes.size() == k)
    {
        printf("%d = ", n);
        printf("%d^%d", finalRes[0], p);
        for(int i = 1; i < finalRes.size(); i++)
            printf(" + %d^%d", finalRes[i], p);
        printf("\n");
    }
    else
        printf("Impossible\n");
    return 0;
}

void solve(int n, int num, vector<int>& factors)
{
    if(num >= k)
    {
        if(n == 0)
        {
            int tempSum = 0;
            for(int i = 0; i < k; i++)
                tempSum += factors[i];
            if(tempSum >= sum)
            {
                finalRes = factors;
                sum = tempSum;
            }
        }
        return;
    }
    int up = (int)sqrt((double)n);
    int low = num > 0 ? factors[num - 1] : 1;
    for(int i = low; i <= up; i++)
    {
        int res = power(i, p);
        if(n >= res)
        {
            factors[num] = i;
            solve(n - res, num + 1, factors);
        }
        else
            return;
    }
}