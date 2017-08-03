#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, D;
	int i, j, flag = 0;
	vector<int> num;
	scanf("%d %d", &N, &D);
	if(N == 0)
	{
        printf("Yes\n");
        printf("0\n");
        return 0;
	}

	while(N)
	{
		num.push_back(N % D);
		N /= D;
	}

	i = 0, j = num.size() - 1;
	for(; i <= j; i++, j--)
	{
		if(num[i] != num[j])
		{
			flag = 1;
			break;
		}
	}

	if(flag == 1)
		printf("No\n");
	else
		printf("Yes\n");
    reverse(num.begin(), num.end());
	for(i = 0; i < num.size() - 1; i++)
		printf("%d ", num[i]);
	printf("%d\n", num[i]);

	return 0;
}
