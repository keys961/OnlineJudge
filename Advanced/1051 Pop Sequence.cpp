#include <cstdio>
#include <stack>

using namespace std;

int sequence[1001];

bool isValid(int n, int capacity);

int main()
{
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);

	for (int i = 0; i < k; i++)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &sequence[i]);
		if (isValid(n, m))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

bool isValid(int n, int capacity)
{
	stack<int> s;
	int i = 1, j = 1;
	for (int i = 1; i <= n; i++)
	{
		while (!s.empty() && s.top() == sequence[j])
		{
			s.pop();
			j++;
		}
		s.push(i);
		if (s.size() > capacity)
			return false;
	}

	while (!s.empty())
	{
		if (s.top() != sequence[j])
			return false;
		s.pop();
		j++;
	}

	return true;
}