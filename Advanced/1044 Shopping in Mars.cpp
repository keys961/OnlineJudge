#include <cstdio>
#include <vector>

using namespace std;

struct Pair
{
	int start;
	int end;
	Pair(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
};

int diamonds[100001];
int minLost = 0x7fffffff;
vector<Pair> res;

void solve(int n, int cost);

int main()
{
	int n, val;
	scanf("%d %d", &n, &val);
	for (int i = 1; i <= n; i++)
		scanf("%d", &diamonds[i]);

	solve(n, val);
	for (int i = 0; i < res.size(); i++)
		printf("%d-%d\n", res[i].start, res[i].end);
	return 0;
}

void solve(int n, int cost)
{
	int ptr1 = 1, ptr2 = 1;
	int sum = 0;
	while (ptr1 <= n)
	{
		while (ptr2 <= n + 1)
		{
			if (sum >= cost)
			{
				int diff = sum - cost;
				if (diff < minLost)
				{
					res.clear();
					minLost = diff;
					res.push_back(Pair(ptr1, ptr2 - 1));
				}
				else if(diff == minLost)
					res.push_back(Pair(ptr1, ptr2 - 1));
				break;
			}
			sum += diamonds[ptr2++];
		}
		sum -= diamonds[ptr1++];
	}
}