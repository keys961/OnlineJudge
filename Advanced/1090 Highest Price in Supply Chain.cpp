#include <cstdio>
#include <cmath>

using namespace std;

int chain[100000];
int height[100000];

int maxHeight = 0;
int c = 0;

int getHeight(int id)
{
	if (chain[id] == -1)
		return 0;
	if (height[id] != 0)
		return height[id];
	int h = 1 + getHeight(chain[id]);
	height[id] = h;
	return h;
}

int main()
{
	int n;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);

	for (int i = 0; i < n; i++)
		scanf("%d", &chain[i]);

	for (int i = 0; i < n; i++)
	{
		int temp = getHeight(i);

		if (temp > maxHeight)
		{
			maxHeight = temp;
			c = 1;
		}
		else if(temp == maxHeight)
			c++;
	}

	printf("%.2f %d\n", p * pow(1 + r / 100, maxHeight), c);

	return 0;
}
